using System.ComponentModel;
using System.Collections.Generic;
using System.Collections;
using System.Collections.ObjectModel;
using System.Reflection;
using System.Reflection.Metadata;
namespace Collections;
public class MyCustomCollection<T>: IEnumerable<T>, IEnumerator<T>
{
    private Node head{get; set;}
    private Node tail{get; set;}
    private Node cur{get; set;}
    private int count;
    public MyCustomCollection()
    {
        head = new Node(default(T)!);
        tail = head;
        cur = head;
        count = 0;
    }
    IEnumerator<T> IEnumerable<T>.GetEnumerator()
    {
        Reset();
        return this;
    }
    public void Add(T item)
    {
        tail.next = new Node(item);
        tail.next.prev = tail;
        tail = tail.next;
        count++;
    }
    IEnumerator IEnumerable.GetEnumerator()
    {
        return ((IEnumerable<T>)this).GetEnumerator();
    }
    public int Count
    {
        get
        {
            return count;
        }
    }
    public T this[int index]
    {
        get
        {
            if(index < 0 || index >= count)
                throw new IndexOutOfRangeException();
            Node? temp = head?.next;
            for(int i = 0; i<index; i++)
            {
                temp = temp!.next!;
            }
            return temp!.val;
        }
        set
        {
            if(index < 0 || index >= count)
                throw new IndexOutOfRangeException();
            Node? temp = head?.next;
            for(int i = 0; i<index; i++)
            {
                temp = temp!.next;
            }
            temp!.val = value;
        }
    }
    public void Remove(T item)
    {
        Node? temp = head?.next;
        while(temp != null)
        {
            if(temp.val!.Equals(item))
            {
                if(cur == temp)
                {
                    RemoveCurrent();
                    return;
                }
                temp.prev!.next = temp.next;
                if(temp.next is not null)
                    temp.next.prev = temp.prev;
                cur = head!;
                return;
            }
            temp = temp.next;   
        }
        throw new MyCustomRemoveException();
    }
    public T RemoveCurrent()
    {
        if(cur == head)
        {
            return default(T)!;
        }
        else
        {
            Node temp = cur;
            if(cur == tail)
            {
                tail = cur.prev!;
            }
            cur.prev!.next = cur?.next;
            cur = cur!.prev;
            count--;
            return temp.val;
        }
    }
    public void Dispose()
    {}
    T IEnumerator<T>.Current
    {
        get
        {
            return cur.val;
        }
    }
    object IEnumerator.Current
    {
        get
        {
            return cur.val!;
        }
    }
    public bool MoveNext()
    {
        if(cur.next is null)
            return false;
        cur = cur.next;
        return true;
    }
    public void Reset()
    {
        cur = head;
    }
    public class Node
    {
        public Node(T value)
        {
            val = value;
        }
        public T val{get; set;}
        public Node? next{get; set;}
        public Node? prev{get; set;}
    }
}
