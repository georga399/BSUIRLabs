#ifndef _CMAP_
#define _CMAP_
#include <memory>
namespace ctl
{

    template <typename T, typename T1>
    class cmap
    {
    protected:
        struct Node {
            Node(T nKey, T1 nValue): key(nKey), data(nValue) {}
            Node(): key(), data() {}
            shared_ptr<Node> left, right;
            weak_ptr<Node> parent;
            bool color; // red - false, black - true
            T key;
            T1 data;
        };
        shared_ptr<Node> grandparent(shared_ptr<Node> node);
        shared_ptr<Node> uncle(shared_ptr<Node> node);
        shared_ptr<Node> sibling(shared_ptr<Node> node);

        void RotateLeft(shared_ptr<Node> node);
        void RotateRight(shared_ptr<Node> node);
        void InsCase1(shared_ptr<Node> node);
        void InsCase2(shared_ptr<Node> node);
        void InsCase3(shared_ptr<Node> node);
        void InsCase4(shared_ptr<Node> node);
        void InsCase5(shared_ptr<Node> node);

        void DelCase1(shared_ptr<Node> node);
        void DelCase2(shared_ptr<Node> node);
        void DelCase3(shared_ptr<Node> node);
        void DelCase4(shared_ptr<Node> node);
        void DelCase5(shared_ptr<Node> node);
        void DelCase6(shared_ptr<Node> node);

    shared_ptr<Node> find(shared_ptr<Node> node, T key);

    shared_ptr<Node> min(shared_ptr<Node> node);
    shared_ptr<Node> max(shared_ptr<Node> node);
    protected: 
        std::shared_ptr<Node> root;
    public:
        cmap(/* args */);
        ~cmap();
        void insert(T key, T1 val);
        void remove(T key);
        T1 findValueWithKey(T key);
        bool contains(T key);
        T1& operator[](T key);
        void clear();
    };
    template <typename T, typename T1>    
    cmap<T, T1>::cmap(/* args */)
    {
    }
    template <typename T, typename T1>
    cmap<T, T1>::~cmap()
    {
    }
    
}

#endif