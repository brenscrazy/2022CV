public class ArrayQueue implements Queue {
    private int size = 0;
    private Object[] elements = new Object[5];
    private int head = 0;
    private int tail = 0;

    public void enqueue(Object element) {
        assert element != null;
        ensureCapacity(size + 1);
        size++;
        elements[tail] = element;
        tail = (tail + 1) % elements.length;
    }

    private void ensureCapacity(int capacity) {
        assert capacity >= 0;
        if (capacity > elements.length) {
            Object[] newElements = new Object[2 * capacity];
            for (int i = head; i < elements.length; i++) {
                newElements[i - head] = elements[i];
            }
            for (int i = 0; i < tail; i++) {
                newElements[i + elements.length - head] = elements[i];
            }
            head = 0;
            tail = size;
            elements = newElements;
        }
    }

    public Object dequeue() {
        assert size > 0;
        Object ret = elements[head];
        elements[head] = null;
        head = (head + 1) % elements.length;
        size--;
        return ret;
    }

    public Object element() {
        assert size > 0;
        return elements[head];
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public void clear() {
        head = 0;
        tail = 0;
        size = 0;
        elements = new Object[5];
    }
}
