import java.util.*;

public class ArraySet<E> extends AbstractSet<E> implements NavigableSet<E> {

    private final ReversiveList<E> reversiveList;
    private final Comparator<? super E> comparator;
    private final static Map<BinSearchOptions, Integer> ENUM_INTS = Map.of(
            BinSearchOptions.MORE, 1,
            BinSearchOptions.LESS, -1,
            BinSearchOptions.INCLUDE, 0,
            BinSearchOptions.EXCLUDE, 1);
    private final static String UNMODIFIABLE_ERROR = "Array set is unmodifiable";

    public ArraySet() {
        this(Collections.emptyList(), null);
    }

    public ArraySet(Collection<? extends E> collection) {
        this(collection, null);
    }

    public ArraySet(Comparator<? super E> comparator) {
        this(Collections.emptyList(), comparator);
    }

    public ArraySet(SortedSet<E> sortedSet) {
        reversiveList = new ReversiveList<>(sortedSet);
        this.comparator = sortedSet.comparator();
    }

    private ArraySet(ReversiveList<E> reversiveList, Comparator<? super E> comparator) {
        this.reversiveList = reversiveList;
        this.comparator = comparator;
    }

    public ArraySet(Collection<? extends E> collection, Comparator<? super E> comparator) {
        Set<E> set = new TreeSet<>(comparator);
        set.addAll(collection);
        reversiveList = new ReversiveList<>(set);
        this.comparator = comparator;
    }

    private void checkForEmptiness(String error) {
        if (isEmpty()) {
            throw new NoSuchElementException(error);
        }
    }

    private boolean checkIndex(int i) {
        return (i >= 0 && i <= reversiveList.size());
    }

    private int getInsertionPoint(int result, BinSearchOptions moreOrLess, BinSearchOptions includeOrExclude) {
        int first = ENUM_INTS.get(moreOrLess);
        int second = ENUM_INTS.get(includeOrExclude);
        if (result < 0) {
            result = -result - 1;
            result = (first > 0) ? result : result - 1;

        } else {
            result += second * first;
        }
        return checkIndex(result) ? result : -1;
    }

    private E getRequiredElement(E key, BinSearchOptions moreOrLess, BinSearchOptions includeOrExclude) {
        int i = getInsertionPoint(Collections.binarySearch(reversiveList, key, comparator), moreOrLess, includeOrExclude);
        return (i >= 0 && i < size()) ? reversiveList.get(i) : null;
    }

    @Override
    public E lower(E o) {
        return getRequiredElement(o, BinSearchOptions.LESS, BinSearchOptions.EXCLUDE);
    }

    @Override
    public E floor(E o) {
        return getRequiredElement(o, BinSearchOptions.LESS, BinSearchOptions.INCLUDE);
    }

    @Override
    public E ceiling(E o) {
        return getRequiredElement(o, BinSearchOptions.MORE, BinSearchOptions.INCLUDE);
    }

    @Override
    public E higher(E o) {
        return getRequiredElement(o, BinSearchOptions.MORE, BinSearchOptions.EXCLUDE);
    }

    @Override
    public E pollFirst() {
        throw new UnsupportedOperationException(UNMODIFIABLE_ERROR);
    }

    @Override
    public E pollLast() {
        throw new UnsupportedOperationException(UNMODIFIABLE_ERROR);
    }

    @Override
    public int size() {
        return reversiveList.size();
    }

    @Override
    public boolean isEmpty() {
        return reversiveList.isEmpty();
    }

    @SuppressWarnings("unchecked")
    @Override
    public boolean contains(Object o) {
        try {
            return Collections.binarySearch(reversiveList, (E) Objects.requireNonNull(o), comparator) >= 0;
        } catch (ClassCastException e) {
            return false;
        }

    }

    @Override
    public Iterator<E> iterator() {
        return Collections.unmodifiableList(reversiveList).iterator();
    }

    @Override
    public NavigableSet<E> descendingSet() {
        return new ArraySet<>(new ReversiveList<>(reversiveList, true), Collections.reverseOrder(comparator));
    }

    @Override
    public Iterator<E> descendingIterator() {
        return new ArraySet<>(new ReversiveList<>(reversiveList, true), Collections.reverseOrder(comparator)).iterator();
    }

    @Override
    public NavigableSet<E> subSet(E e, boolean b, E e1, boolean b1) {
        if (comparator.compare(e, e1) > 0) {
            throw new IllegalArgumentException("Left border is greater that the right one.");
        }
        int left = getInsertionPoint(
                Collections.binarySearch(reversiveList, e, comparator),
                BinSearchOptions.MORE,
                b ? BinSearchOptions.INCLUDE : BinSearchOptions.EXCLUDE);
        int right = getInsertionPoint(
                Collections.binarySearch(reversiveList, e1, comparator),
                BinSearchOptions.MORE,
                b1 ? BinSearchOptions.EXCLUDE : BinSearchOptions.INCLUDE);
        if (right < left || left == -1 || right == -1) {
            return new ArraySet<>(comparator);
        }
        return new ArraySet<>(reversiveList.subList(left, right), comparator);
    }

    @Override
    public NavigableSet<E> headSet(E e, boolean b) {
        if (isEmpty()) {
            return new ArraySet<>(comparator);
        }
        try {
            return subSet(reversiveList.get(0), true, e, b);
        } catch (IllegalArgumentException ex) {
            return new ArraySet<>(comparator);
        }
    }

    @Override
    public NavigableSet<E> tailSet(E e, boolean b) {
        if (isEmpty()) {
            return new ArraySet<>(comparator);
        }
        try {
            return subSet(e, b, reversiveList.get(reversiveList.size() - 1), true);
        } catch (IllegalArgumentException ex) {
            return new ArraySet<>(comparator);
        }
    }

    @Override
    public Comparator<? super E> comparator() {
        return comparator;
    }

    @Override
    public SortedSet<E> subSet(E e, E e1) {
        return subSet(e, true, e1, false);
    }

    @Override
    public SortedSet<E> headSet(E e) {
        return headSet(e, false);
    }

    @Override
    public SortedSet<E> tailSet(E e) {
        return tailSet(e, true);
    }

    @Override
    public E first() {
        checkForEmptiness("Array set is empty. Can't get first element.");
        return reversiveList.get(0);
    }

    @Override
    public E last() {
        checkForEmptiness("Array set is empty. Can't get last element.");
        return reversiveList.get(reversiveList.size() - 1);
    }
}
