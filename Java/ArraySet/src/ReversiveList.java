import java.util.*;

public class ReversiveList<E> extends AbstractList<E> implements RandomAccess {

    private boolean isReversed = false;
    private final List<E> arrayList;

    public ReversiveList(Collection<? extends E> c) {
        arrayList = new ArrayList<>(c);
    }

    public ReversiveList() {
        arrayList = new ArrayList<>();
    }

    public ReversiveList(List<E> list, boolean isReversed) {
        if (list instanceof ReversiveList) {
            this.arrayList = ((ReversiveList<E>) list).getList();
            this.isReversed = ((ReversiveList<E>) list).isReversed ^ isReversed;
            return;
        }
        this.arrayList = list;
        this.isReversed = isReversed;
    }

    public List<E> getList() {
        return arrayList;
    }

    public ReversiveList<E> getReversed() {
        return new ReversiveList<E>(arrayList, !isReversed);
    }

    @Override
    public E get(int i) {
        return isReversed ? arrayList.get(size() - (i + 1)) : arrayList.get(i);
    }

    @Override
    public int size() {
        return arrayList.size();
    }

}
