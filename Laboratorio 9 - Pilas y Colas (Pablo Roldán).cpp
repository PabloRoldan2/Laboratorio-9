#include <iostream>
#include <stack>
#include <queue>
#include <vector> // Necesitas incluir vector

using namespace std;

// Clase Pila para manejar una pila de enteros 
class Pila {
public:
    void push(int valor) { stack_.push(valor); }  // Agrega un valor a la pila
    int pop() {  // remueve y retorna el valor en la parte superior de la pila
        int valor = stack_.top();
        stack_.pop();
        return valor;
    }
    bool empty() const { return stack_.empty(); } // Verifica si la pila está vacía
private:
    stack<int> stack_;  // Objeto de tipo stack para almacenar los enteros
};

// Clase Cola para manejar una cola de enteros
class Cola {
public:
    void enqueue(int valor) { queue_.push(valor); } // Agrega un valor a la cola
    int dequeue() { // Remueve y retorna el valor en la parte frontal de la cola
        int valor = queue_.front();
        queue_.pop();
        return valor;
    }
    bool empty() const { return queue_.empty(); } // Verifica si la cola está vacía
private:
    queue<int> queue_; // Objeto de tipo queue para almacenar los enteros
};

// Clase Tarea para representar una tarea con un número
class Tarea {
public:
    int numero; // Número de la tarea
    Tarea(int num) : numero(num) {} // Constructor que inicializa la tarea con un número dado
};

int main() {
    Pila pila; // Crear una instancia de la clase Pila
    Cola cola; // Crear una instancia de la clase Cola
    vector<Tarea> tareas; // Crear un vector para almacenar las tareas
	system("color 8e");
    int opcion;
    do {
    	system("cls");
    	cout << "----------Menu-------------" << endl;
        cout << "1. Agregar nueva tarea" << endl;
        cout << "2. Completar la ultima tarea" << endl;
        cout << "3. Atender la tarea mas antigua" << endl;
        cout << "4. Mostrar todas las tareas" << endl;
        cout << "5. Salir" << endl;
        cout << "---------------------------" << endl;
        cin >> opcion;
        system("cls");

        switch (opcion) {
            case 1: {
                int nuevoNumero;
                cout << "Ingrese el numero de la nueva tarea: ";
                cin >> nuevoNumero;  // Leer el número de la nueva tarea
                tareas.push_back(Tarea(nuevoNumero)); // Agregar la tarea al vector
                cola.enqueue(nuevoNumero);  // Agregar la tarea a la cola
                pila.push(nuevoNumero);     // Agregar la tarea a la pila
                break;
                system("pause");
            	}
            case 2:
                if (!pila.empty()) {
                    cout << "Ultima tarea completada: " << pila.pop() << "\n"; // Completa y muestra la última tarea
                    tareas.pop_back(); // Remueve la última tarea del vector
                } else {
                    cout << "No hay tareas pendientes.\n";
                }
                system("pause");
                break;
            case 3:
    			if (!cola.empty()) {
       			int numeroTarea = cola.dequeue();
        			cout << "Atendiendo la tarea mas antigua: " << numeroTarea << "\n"; 
       			for (auto it = tareas.begin(); it!= tareas.end(); ++it) { // Busca y eliminaa la tarea correspondiente del vector tareas
           		if ((*it).numero == numeroTarea) {
                	tareas.erase(it); // Eliminar la tarea encontrada
                break; // Sale del bucle una vez encontrada y eliminada la tarea
            			}
       				}
   				} else {
       				cout << "No hay tareas en cola.\n";
   				}
   				system("pause");
    			break;
            case 4:
                cout << "Todas las tareas:\n";
                for (const auto& tarea : tareas) {
                    cout << tarea.numero << "\n"; // Muestra todas las tareas
                }
                system("pause");
                break;
            case 5:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } while (opcion != 5);

    return 0;
}
