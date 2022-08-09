public interface Queue {

    public void enqueue(Object element);

    public Object dequeue();

    public Object element();

    public int size();

    public boolean isEmpty();

    public void clear();

}
