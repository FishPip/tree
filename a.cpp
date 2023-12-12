#include <iostream>
#include <string>
#include <vector>

class Node {
private:
    Node* fater;
    Node* left_child;
    Node* rigth_child;
    std::string data;
    int site; /* wenn das Kind ein linkes Kind ist, dann ist die site == 0, sonst site == 1*/

public:
    void set_fater(Node* new_fater) {
        fater = new_fater;
    }
    void set_left_child(Node* new_child) {
        left_child = new_child;
    }
    void set_rigth_child(Node* new_child) {
        rigth_child = new_child;
    }
    void set_data(std::string new_data) {
        data = new_data;
    }
    void set_site(int new_site) {
        site = new_site;
    }

    Node* get_fater() {
        return fater;
    }
    Node* get_left_child() {
        return left_child;
    }
    Node* get_rigth_child() {
        return rigth_child;
    }
    std::string get_Data() {
        return data;
    }
    int get_site() {
        return site;
    }
    
    Node(Node* new_fater, Node* new_left_child, Node* new_rigth_child, std::string data, int new_site) {
        set_fater(new_fater);
        set_left_child(new_left_child);
        set_rigth_child(new_rigth_child);
        set_site(new_site);
    }

    ~Node() {
        Node* fater = get_fater();
        if (fater != NULL) {
            if (get_site() == 0)
                fater->set_left_child(NULL);
            else
                fater->set_rigth_child(NULL);
        }
    }
};

class Tree {
private:
    Node* wurtzel = NULL;

public:
    Node* get_node(std::string adress) {
        /* Adress sieht wie folg aus: (Beispiel: 01001);
           0 steht für links, 1 steht für rechts */


        Node* current_node = wurtzel;
        std::cout << wurtzel << std::endl;
        for (char i : adress) {
            if (i == '0') {
                current_node = current_node->get_left_child();
            }
            else {
                current_node = current_node->get_rigth_child();
            }
        }

        return current_node;
    }

    void add_new_left_child_to_node(std::string adress, std::string new_data) {
        Node* new_node = new Node(NULL, NULL, NULL, new_data, 0);
        Node* current_node = get_node(adress);
        current_node->set_left_child(new_node);
    }

    void add_new_rigth_child_to_node(std::string adress, std::string new_data) {
        Node* new_node = new Node(NULL, NULL, NULL, new_data, 1);
        Node* current_node = get_node(adress);
        current_node->set_rigth_child(new_node);
    }

    Tree() {
        Node* wurtzel = new Node(NULL, NULL, NULL, "0", 0);
    }

    ~Tree() {
        Node* current_element = wurtzel;

        while (true) {
            if (current_element == NULL) 
                break;
            
            Node* left_child = current_element->get_left_child();
            if (left_child != NULL) 
                current_element = left_child;
             
            Node* rigth_child = current_element->get_rigth_child();
            if (rigth_child != NULL) 
                current_element = rigth_child;
            
            Node* new_current_element = current_element->get_fater();
            delete current_element;
            current_element = new_current_element;
        }
    }

};

int main()
{
    Tree* a = new Tree();

    a->add_new_left_child_to_node("", "1");
    // std::cout << a->get_node(00) << std::endl;

    delete a;
}
