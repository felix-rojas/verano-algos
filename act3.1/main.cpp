/** 
 * Alexia Castillo Diaz  y Félix Javier Rojas Gallardo
* Ejemplo que implementa un Binary Search Tree (BST)
* y los recorridos inorder, postorder, y preorder
*
* Compilacion para debug:  
*    g++ -std=c++17 -g -o main *.cpp 
* Ejecucion con valgrind:
*    nix-env -iA nixpkgs.valgrind
*    valgrind --leak-check=full ./main
*
* Compilacion para ejecucion:  
*    g++ -std=c++17 -O3 -o main *.cpp 
* Ejecucion:
*    ./main
**/

#include <iostream>
#include "BST.h"

int main() {
  std::cout << "Ejemplo de un Binary Search Tree (BST)\n";

  BST<int> myBST;
  myBST.insert(10);
  myBST.insert(20);
  myBST.insert(30);
  myBST.insert(15);
  myBST.insert(5);
  myBST.insert(115);
  myBST.insert(3);
  myBST.insert(3);

  /*
                    10
            5               20          
        3             15          30
                                      115                           
  */
  
  myBST.print();

  std::cout << "What level am I: "  << std::endl;
  std::cout << myBST.whatlevelami(10) << std::endl;

  
  std::cout << "Recorrido inorder" << std::endl;
  myBST.callInorder();
  std::cout << "Recorrido preorder" << std::endl;
  myBST.callPreOrder();
  std::cout << "Recorrido postorder" << std::endl;
  myBST.callPostOrder();
  std::cout << "Recorrido level by level" << std::endl;
  myBST.callLevelOrder();

  std::cout << "Visit:" << std::endl;
  myBST.callvisit(1);  
   std::cout << "Ancestor: "  << std::endl;
  myBST.ancestors(15);
  
  std::cout << "search(15) " << myBST.search(15) << std::endl;
  std::cout << "search(22) " << myBST.search(22) << std::endl;
  std::cout << "search(3) " << myBST.search(3) << std::endl;
  
  // Borrar nodo sin hijos
  std::cout << "deleteNode(115) " << std::endl;
  myBST.deleteNode(115);
  myBST.print();

  // Borrar nodo con un hijo
  std::cout << "deleteNode(5) " << std::endl;
  myBST.deleteNode(5);
  myBST.print();

  // Borrar nodo con dos hijos
  std::cout << "deleteNode(20) " << std::endl;
  myBST.deleteNode(20);
  myBST.print();

  std::cout << "Height: "  << std::endl;
  myBST.callheight();

}