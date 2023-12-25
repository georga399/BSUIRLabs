using System.ComponentModel;
using System.Collections.Generic;
using System.Collections;
using System.Collections.ObjectModel;
using System.Reflection;
using Interfaces;
namespace Collections;
public class MyCustomCollection<T>: ICustomCollection<T>
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
    public void Add(T item)
    {
        tail.next = new Node(item);
        tail.next.prev = tail;
        tail = tail.next;
        count++;
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
                temp.prev!.next = temp.next;
                if(temp.next is not null)
                    temp.next.prev = temp.prev;
                cur = head!;
                count--;
                return;

            }
        }
    }
    public T Current()
    {
        return cur.val;
    }
    public void Next()
    {
        if(cur.next is null)
            cur = head;
        else
            cur = cur.next;
    }
    public void Reset()
    {
        cur = head;
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
