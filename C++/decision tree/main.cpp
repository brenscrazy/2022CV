#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <sstream>

using namespace std;

class Decider {
public:
    virtual int decide(vector<double> &x) { return 0;};
    virtual void toString(vector<vector<string>>& res) {}
};

class DecisionNode : public Decider {
public:
    double m;
    int i;
    Decider *left;
    Decider *right;

    DecisionNode(double m, int i, Decider *left, Decider *right) : left(left), right(right) {
        this->m = m;
        this->i = i;
    }

    void toString(vector<vector<string>>& res) override {
        int ind = res.size();
        std::ostringstream strs;
        strs << m;
        std::string str = strs.str();
        res.push_back({"Q", std::to_string(i + 1), str, std::to_string(ind + 2)});
        left->toString(res);
        res[ind].push_back(std::to_string(res.size() + 1));
        right->toString(res);
    }

    int decide(vector<double> &x) override {
        if (x[i] <= m) {
            return left->decide(x);
        }
        return right->decide(x);
    }
};

class DecisionLeaf : public Decider {
public:
    int y;

    explicit DecisionLeaf(int y) {
        this->y = y;
    }

    int decide(vector<double> &x) override {
        return y;
    }
    void toString(vector<vector<string>>& res) override {
        int n = res.size();
        res.emplace_back();
        res[n].push_back("C");
        res[n].push_back(std::to_string(y + 1));
    }

};

class Dataset {
public:
    int classes;
    int d;
    int n;
    vector<vector<double>*> * dataset;

    explicit Dataset(vector<vector<double>*> * dataset, int classes=2) : dataset(dataset) {
        d = dataset->size();
        if (d == 0) {
            return ;
        }
        this->classes = classes;
        this->n = dataset[0].size() - 2;
        this->dataset = dataset;
    }

    int classByIndex(int index) {
        vector<double> * v = (*dataset)[index];
        double classs = (*v)[(*v).size() - 2];
        return (int)(*v)[(*v).size() - 2];
    }

    double weightByIndex(int index) {
        vector<double> * v = (*dataset)[index];
        double classs = (*v)[v->size() - 1];
        return (*v)[v->size() - 1];
    }

    double getFeature(int row, int featureIndex) {
        return (*(*dataset)[row])[featureIndex];
    }

    int maxClass() {
        vector<int> count(classes);
        for (int i = 0; i < d; i++) {
            count[classByIndex(i)]++;
        }
        int max = 0;
        int res = 0;
        for (int i = 0; i < classes; i++) {
            if (count[i] > max) {
                res = i;
                max = count[i];
            }
        }
        return res;
    }

    pair<double, double> bestBorderAtCollumn(int column);

    void sortByColumn(int column);

    pair<struct Dataset *, struct Dataset *> splitByColumnAndBorder(int column, double border);

    pair<pair<struct Dataset *, struct Dataset *>, pair<double, double>> splitByBestBorder();
};

class GiniCalculator {
public:
    Dataset *dataset;
    int classes;
    double total = 0;
    vector<double> leftBranchWeights;
    vector<double> rightBranchWeights;
    vector<double> weightsSum;

    GiniCalculator(Dataset *dataset) : dataset(dataset) {
        classes = dataset->classes;
        count();
    }

    void count() {
        leftBranchWeights = vector<double>(classes);
        rightBranchWeights = vector<double>(classes);
        weightsSum = vector<double>(classes);
        for (int i = 0; i < dataset->d; i++) {
            int cl = dataset->classByIndex(i);
            weightsSum[cl] += dataset->weightByIndex(i);
            rightBranchWeights[dataset->classByIndex(i)] += dataset->weightByIndex(i);
            total += dataset->weightByIndex(i);
        }
    }

    double calculateGiniGain(const vector<double>& weights) {
        double totalW = 0;
        for (double d : weights) {
            totalW += d;
        }
        double res = 0;
        for (double d : weights) {
            res += pow(d / totalW, 2);
        }
        return totalW * (1 - res);
    }

    double calculateF() {
        auto a = calculateGiniGain(weightsSum);
        auto b = calculateGiniGain(leftBranchWeights);
        auto c = calculateGiniGain(rightBranchWeights);
        return calculateGiniGain(weightsSum) / total - calculateGiniGain(leftBranchWeights) / total - calculateGiniGain(rightBranchWeights) / total;
    }

    void moveFromRightToLeft(int index) {
        rightBranchWeights[dataset->classByIndex(index)] -= dataset->weightByIndex(index);
        leftBranchWeights[dataset->classByIndex(index)] += dataset->weightByIndex(index);
    }

};

auto sortcol(const int col)
{
    return [=](const vector<double>* v1, const vector<double >* v2) { return (*v1)[col] < (*v2)[col];};
}

void Dataset::sortByColumn(int column) {
    sort(dataset->begin(), dataset->end(), sortcol(column));
}

pair<double, double> Dataset::bestBorderAtCollumn(int column) {
    sortByColumn(column);
    auto giniCalc = GiniCalculator(this);
    giniCalc.moveFromRightToLeft(0);
    double bestF = 0;
    double bestBorder = 0;
    for (int row = 0; row < d - 1; row++) {
        double currentX = getFeature(row, column);
        double nextX = getFeature(row + 1, column);
        if (currentX != nextX) {
            double F = giniCalc.calculateF();
            if (F > bestF) {
                bestBorder = (currentX + nextX) / 2;
                bestF = F;
            }
        }
        giniCalc.moveFromRightToLeft(row + 1);
    }
    return {bestBorder, bestF};
}

pair<Dataset*, Dataset*> Dataset::splitByColumnAndBorder(int column, double border) {
    vector<vector<double>*>* left = new vector<vector<double>*>(0);
    vector<vector<double>*>* right = new vector<vector<double>*>(0);
    for (auto vect : *dataset) {
        if ((*vect)[column] <= border) {
            left->push_back(vect);
        } else {
            right->push_back(vect);
        }
    }
    return {new Dataset(left, classes), new Dataset(right, classes)};
}

pair<pair<Dataset*, Dataset*>, pair<double, double>> Dataset::splitByBestBorder() {
    double bestF = 0;
    double bestBorder = 0;
    int bestColumn = 0;
    for (int column = 0; column < n; column++) {
        auto pair = bestBorderAtCollumn(column);
        auto border = pair.first;
        auto F = pair.second;
        if (F > bestF) {
            bestBorder = border;
            bestF = F;
            bestColumn = column;
        }
    }
    return {splitByColumnAndBorder(bestColumn, bestBorder), {bestColumn, bestBorder}};
}

class BinaryDecisionTreeBuilder {
public:
    Dataset * dataset;

    BinaryDecisionTreeBuilder(Dataset* dataset): dataset(dataset) {
    }

    Decider* treeBuilder(int maxH=1e9, int currentH=0) {
        if (currentH >= maxH) {
            auto ret = new DecisionLeaf(dataset->maxClass());
            return ret;
        }
        auto pair = dataset->splitByBestBorder();
        auto dsLeft = pair.first.first;
        auto dsRight = pair.first.second;
        auto column = pair.second.first;
        auto border = pair.second.second;
        if (dsLeft->d == 0 || dsRight->d == 0) {
            auto ret = new DecisionLeaf(dataset->maxClass());
            return ret;
        }
        auto treeLeft = BinaryDecisionTreeBuilder(dsLeft).treeBuilder(maxH, currentH + 1);
        auto treeRight = BinaryDecisionTreeBuilder(dsRight).treeBuilder(maxH, currentH + 1);
        auto ret = new DecisionNode(border, column, treeLeft, treeRight);
        return ret;
    }

    Decider* buildTree(int maxH=1e9) {
        return treeBuilder(maxH);
    }

};

void listTree(Decider* decider, vector<vector<string>>& res) {
    if(auto* v = dynamic_cast<DecisionLeaf*>(decider)) {
        // old was safely casted to NewType
        int n = res.size();
        res.emplace_back();
        res[n].push_back("C");
        res[n].push_back(std::to_string(v->y + 1));
    }
    if(auto* v = dynamic_cast<DecisionNode*>(decider)) {
        int ind = res.size();
        std::ostringstream strs;
        strs << v->m;
        std::string str = strs.str();
        res.push_back({"Q", std::to_string(v->i + 1), str, std::to_string(ind + 2)});
        listTree(v->left, res);
        res[ind].push_back(std::to_string(res.size() + 1));
        listTree(v->right, res);
    }
}

int main() {
    int m, k, h, n;
    cin >> m >> k >> h >> n;
    vector<vector<double>*> *ds=new vector<vector<double>* >(0);;
    for (int i = 0; i < n; i++) {
        vector<double> *line = new vector<double >(0);
        for (int j = 0; j < m + 1; j++) {
            double d;
            cin >> d;
            if (j == m) {
                d -= 1;
            }
            line->push_back(d);
        }
        line->push_back(1.0 / n);
        ds->push_back(line);
    }
    auto d = Dataset(ds, k);
    Decider* decider = BinaryDecisionTreeBuilder(&d).buildTree(h);
    vector<vector<string>> res;
    decider->toString(res);
    cout << res.size() << '\n';
    for (const auto& arr : res) {
        for (const auto& str : arr) {
            cout << str << ' ';
        }
        cout << '\n';
    }

    return 0;
}
