#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Item class
class Item
{
private:
    string itemName;
    string category;
    int price;

public:
    Item(string name, string cat, int p) : itemName(name), category(cat), price(p) {}
    string getItemName() { return itemName; }
    string getCategory() { return category; }
    int getPrice() { return price; }
    void print()
    {
        cout << "Item Name: " << itemName << "  Category: " << category << "  Price: $" << price << endl;
    }
    bool operator<(const Item &other) const
    {
        return itemName < other.itemName;
    }
    bool operator>(const Item &other) const
    {
        return itemName > other.itemName;
    }
    bool operator==(const Item &other) const
    {
        return itemName == other.itemName;
    }
};

// Node struct
struct Node
{
    Item item;
    Node *left;
    Node *right;
    int height;

    Node(Item itm) : item(itm), left(nullptr), right(nullptr), height(1) {}
};

// AVL Tree class
class AVLTree
{
private:
    Node *rootByName;
    Node *rootByPrice;

    int height(Node *node)
    {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    int balanceFactor(Node *node)
    {
        if (node == nullptr)
            return 0;
        return height(node->left) - height(node->right);
    }

    void updateHeight(Node *node)
    {
        node->height = 1 + max(height(node->left), height(node->right));
    }

    Node *rotateLeft(Node *node)
    {
        Node *newRoot = node->right;
        node->right = newRoot->left;
        newRoot->left = node;
        updateHeight(node);
        updateHeight(newRoot);
        return newRoot;
    }

    Node *rotateRight(Node *node)
    {
        Node *newRoot = node->left;
        node->left = newRoot->right;
        newRoot->right = node;
        updateHeight(node);
        updateHeight(newRoot);
        return newRoot;
    }

    Node *insertByName(Node *node, Item item)
    {
        if (node == nullptr)
            return new Node(item);

        // Compare based on name
        if (item < node->item)
            node->left = insertByName(node->left, item);
        else if (item > node->item)
            node->right = insertByName(node->right, item);
        else
        {
            // If names are equal, compare based on category
            if (item.getPrice() < node->item.getPrice())
                node->left = insertByName(node->left, item);
            else
                node->right = insertByName(node->right, item);
        }

        updateHeight(node);

        int balance = balanceFactor(node);

        // Left Left Case
        if (balance > 1 && item < node->left->item)
            return rotateRight(node);

        // Right Right Case
        if (balance < -1 && item > node->right->item)
            return rotateLeft(node);

        // Left Right Case
        if (balance > 1 && item > node->left->item)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Right Left Case
        if (balance < -1 && item < node->right->item)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    Node *insertByPrice(Node *node, Item item)
    {
        if (node == nullptr)
            return new Node(item);

        // Compare based on price
        if (item.getPrice() < node->item.getPrice())
            node->left = insertByPrice(node->left, item);
        else if (item.getPrice() > node->item.getPrice())
            node->right = insertByPrice(node->right, item);
        else
        {
            // If prices are equal, compare based on name
            if (item < node->item)
                node->left = insertByPrice(node->left, item);
            else
                node->right = insertByPrice(node->right, item);
        }

        updateHeight(node);

        int balance = balanceFactor(node);

        // Left Left Case
        if (balance > 1 && item.getPrice() < node->left->item.getPrice())
            return rotateRight(node);

        // Right Right Case
        if (balance < -1 && item.getPrice() > node->right->item.getPrice())
            return rotateLeft(node);

        // Left Right Case
        if (balance > 1 && item.getPrice() > node->left->item.getPrice())
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Right Left Case
        if (balance < -1 && item.getPrice() < node->right->item.getPrice())
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    Node *findMin(Node *node)
    {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    Node *removeByName(Node *node, Item item)
    {
        if (node == nullptr)
            return nullptr;

        if (item < node->item)
            node->left = removeByName(node->left, item);
        else if (item > node->item)
            node->right = removeByName(node->right, item);
        else
        {
            if (node->left == nullptr || node->right == nullptr)
            {
                Node *temp = node->left ? node->left : node->right;

                if (temp == nullptr)
                {
                    temp = node;
                    node = nullptr;
                }
                else
                    *node = *temp;
                delete temp;
            }
            else
            {
                Node *temp = findMin(node->right);
                node->item = temp->item;
                node->right = removeByName(node->right, temp->item);
            }
        }

        if (node == nullptr)
            return nullptr;

        updateHeight(node);

        int balance = balanceFactor(node);

        // Left Left Case
        if (balance > 1 && balanceFactor(node->left) >= 0)
            return rotateRight(node);

        // Left Right Case
        if (balance > 1 && balanceFactor(node->left) < 0)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Right Right Case
        if (balance < -1 && balanceFactor(node->right) <= 0)
            return rotateLeft(node);

        // Right Left Case
        if (balance < -1 && balanceFactor(node->right) > 0)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    Node *removeByPrice(Node *node, Item item)
    {
        if (node == nullptr)
            return nullptr;

        if (item.getPrice() < node->item.getPrice())
            node->left = removeByPrice(node->left, item);
        else if (item.getPrice() > node->item.getPrice())
            node->right = removeByPrice(node->right, item);
        else
        {
            if (node->left == nullptr || node->right == nullptr)
            {
                Node *temp = node->left ? node->left : node->right;

                if (temp == nullptr)
                {
                    temp = node;
                    node = nullptr;
                }
                else
                    *node = *temp;
                delete temp;
            }
            else
            {
                Node *temp = findMin(node->right);
                node->item = temp->item;
                node->right = removeByPrice(node->right, temp->item);
            }
        }

        if (node == nullptr)
            return nullptr;

        updateHeight(node);

        int balance = balanceFactor(node);

        // Left Left Case
        if (balance > 1 && balanceFactor(node->left) >= 0)
            return rotateRight(node);

        // Left Right Case
        if (balance > 1 && balanceFactor(node->left) < 0)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Right Right Case
        if (balance < -1 && balanceFactor(node->right) <= 0)
            return rotateLeft(node);

        // Right Left Case
        if (balance < -1 && balanceFactor(node->right) > 0)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    void inorderTraversalByName(Node *node)
    {
        if (node == nullptr)
            return;
        inorderTraversalByName(node->left);
        node->item.print();
        inorderTraversalByName(node->right);
    }

    void inorderTraversalByPrice(Node *node)
    {
        if (node == nullptr)
            return;
        inorderTraversalByPrice(node->left);
        node->item.print();
        inorderTraversalByPrice(node->right);
    }

    void reverseInorderTraversalByName(Node *node)
    {
        if (node == nullptr)
            return;
        reverseInorderTraversalByName(node->right);
        node->item.print();
        reverseInorderTraversalByName(node->left);
    }

    void reverseInorderTraversalByPrice(Node *node)
    {
        if (node == nullptr)
            return;
        reverseInorderTraversalByPrice(node->right);
        node->item.print();
        reverseInorderTraversalByPrice(node->left);
    }

public:
    AVLTree() : rootByName(nullptr), rootByPrice(nullptr) {}

    void add(Item item)
    {
        rootByName = insertByName(rootByName, item);
        rootByPrice = insertByPrice(rootByPrice, item);
    }

    void removeByName(Item item)
    {
        rootByName = removeByName(rootByName, item);
    }

    void removeByPrice(Item item)
    {
        rootByPrice = removeByPrice(rootByPrice, item);
    }

    void displayInorder()
    {
        inorderTraversalByName(rootByName);
    }
    void displayInorderByName()
    {
        inorderTraversalByName(rootByName);
    }

    void displayInorderByPrice()
    {
        inorderTraversalByPrice(rootByPrice);
    }

    void displayInorderDescendingByName()
    {
        reverseInorderTraversalByName(rootByName);
    }

    void displayInorderDescendingByPrice()
    {
        reverseInorderTraversalByPrice(rootByPrice);
    }

    ~AVLTree() {}
};

int main()
{
    AVLTree avl;

    Item item1{"chocolate milk", "drink", 10};
    Item item2{"bananas", "fruit", 75};
    Item item3{"pepsi", "drink", 20};
    Item item4{"cheddar cheese", "dairy", 49};
    Item item5{"tuna", "meat", 90};
    Item item6{"fanta orange", "drink", 20};
    Item item7{"yought", "dairy", 13};
    Item item8{"mint gum", "candy", 2};
    Item item9{"water", "drink", 9};
    Item item10{"apples", "fruit", 66};
    Item item11{"beef", "meat", 284};
    Item item12{"cheese cake", "dessert", 68};

    avl.add(item1);
    avl.add(item2);
    avl.add(item3);
    avl.add(item4);
    avl.add(item5);
    avl.add(item6);
    avl.add(item7);
    avl.add(item8);
    avl.add(item9);
    avl.add(item10);
    avl.add(item11);
    avl.add(item12);

    cout << "AVL Tree Inorder Traversal (Normal Display):" << endl;
    avl.displayInorder();
    cout << "-------------------------------------------------------";
    cout << endl;

    cout << "AVL Tree items sorting ascending by Name:" << endl;
    avl.displayInorderByName();
    cout << "-------------------------------------------------------";
    cout << endl;
    cout << "AVL Tree items sorting descending by Name:" << endl;
    avl.displayInorderDescendingByName();
    cout << "-------------------------------------------------------";
    cout << endl;

    cout << "AVL Tree items sorting ascending by Price:" << endl;
    avl.displayInorderByPrice();
    cout << "-------------------------------------------------------";
    cout << endl;

    cout << "AVL Tree items sorting descending by Price:" << endl;
    avl.displayInorderDescendingByPrice();
    cout << "-------------------------------------------------------";
    cout << endl;

    // Remove items
    cout << "Removing 'bananas' by name:" << endl;
    avl.removeByName(Item("bananas", "", 0));
    avl.displayInorderByName();
    cout << "-------------------------------------------------------";
    cout << endl;

    cout << "Removing 'cheese cake' by price:" << endl;
    avl.removeByPrice(Item("", "", 68));
    avl.displayInorderByPrice();
    cout << "-------------------------------------------------------";
    cout << endl;

    return 0;
}
