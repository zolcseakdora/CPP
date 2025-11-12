#include "Directory.h" 
#include "File.h"
#include "FileSystemItem.h"
#include <iostream>

using namespace std;

int main() {
    cout << "--- Fájlrendszer szimuláció ---" << endl;
    
    // 1. Hozz létre egy gyökér könyvtárat (root)
    Directory* root = new Directory("root");

    // Létrehozom az alkönyvtárakat és fájlokat
    Directory* documents = new Directory("documents");
    Directory* pictures = new Directory("pictures");

    File* report = new File("report.txt", 1500);         
    File* notes = new File("notes.txt", 800);            
    File* photo1 = new File("photo1.jpg", 2048000);      
    File* photo2 = new File("photo2.jpg", 1856000);      
    File* readme = new File("readme.txt", 500);          

    // 2. Adj hozzá fájlokat és alkönyvtárakat (operátor += demonstrálása)
    *documents += report; 
    *documents += notes;
    
    *pictures += photo1;
    *pictures += photo2;

    *root += documents;
    *root += pictures;
    *root += readme;
    
    cout << "\n1. Kezdeti struktúra és méretek:" << endl;
    // 3. Jelenítsd meg a teljes struktúrát
    root->display(); 

    // 4. Írd ki a teljes méret
    cout << "\nTeljes méret a root könyvtárban: " << root->getSize() << " bytes." << endl;

    // 5. Keress egy fájlt név alapján
    cout << "\n2. Keresés (photo1.jpg):" << endl;
    FileSystemItem* foundItem = root->find("photo1.jpg");
    if (foundItem) {
        cout << "Találat!" << endl;
        // Operátor << demonstrálása
        cout << "Megtalált elem: " << *foundItem << endl;
    } 

    // 6. Távolíts el egy elemet (operátor -= demonstrálása)
    cout << "\n3. Elem eltávolítása (pictures/ könyvtár):" << endl;
    *root -= "pictures"; 
    
    cout << "Törlés után:" << endl;
    root->display(); 
    cout << "Új root méret: " << root->getSize() << " bytes." << endl;

    // 7. Készíts másolatot egy könyvtárról (clone és Másoló Konstruktor/Deep Copy)
    cout << "\n4. Könyvtár másolása (Deep Copy):" << endl;
    Directory* rootCopy = dynamic_cast<Directory*>(root->clone());
    
    File* tempFile = new File("temp.dat", 1234);
    *rootCopy += tempFile;

    cout << "Másolat megjelenítése (extra temp.dat-tal):" << endl;
    rootCopy->display();
    
    cout << "\nEredeti Root tartalom ellenőrzése (változatlan):" << endl;
    root->display();
    
    // 8. Demonstráld az operátor < függvényt (név szerinti összehasonlítás)
    cout << "\n5. Összehasonlítás (< operátor):" << endl;
    cout << "report.txt < notes.txt? " << (*report < *notes ? "IGEN" : "NEM") << endl; 

    // Memória felszabadítása
    delete root;
    delete rootCopy;

    return 0;
}