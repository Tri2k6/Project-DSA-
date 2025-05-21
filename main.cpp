#include "Priority_Queue.h"
using namespace std;

int print_menu()
{
    cout << "Menu: \n0. End program \n1. Construct new heap \n2. Check empty \n3. Heap size \n4. Push item\n5. Pop item \n6. Remove item \n7. Clear heap \n8. Print heap";
    int n = 0;
    do
    {
        cout << "\nChoose an operation: ";
        cin >> n;
    } while (n > 8 || n < 0);

    return n;
}


int main() {
    int selection = 0;
    PriorityQueue<int> heap;
    do
    {
        selection = print_menu();
        switch (selection)
        {
        case 1:
        {
            int n;
            vector<int> a;
            cout << "Enter number of array: "; cin >> n;
            for (int i = 0;i < n;i++) {
                int x; 
                cin >> x;
                a.push_back(x);
            }
            
            heap.buildHeap(a);

            break;
        }
        case 2:
        {
            if (heap.isEmpty())
                std::cout << "Heap is empty\n";
            else
                std::cout << "Heap is not empty\n";
            break;
        }
        case 3:
        {
            std::cout << "Your heap's size is: " << heap.size() << '\n';
            break;
        }
        case 4:
        {
            int n;
            std::cout << "Enter value for insertion: ";
            std::cin >> n;
            heap.push(n);
            break;
        }

        case 5: 
        {
            heap.pop();
            break;
        }

        case 6:
        {
            int n;
            std::cout << "Enter value for deletion: ";
            std::cin >> n;
            heap.remove(n);
            break;
        }
        case 7:
        {
            heap.clear();
            std::cout << "Heap cleared\n";
            break;
        }
        case 8:
        {
            std::cout << "This is your heap:\n";
            heap.print();
            break;
        }
        }

    } while (selection);
    
    return 0;
}