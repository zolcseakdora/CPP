#include "File.h"
#include "FileSystemItem.h"

#include <iostream>
using namespace std;

void File::display(int depth) const {
    for (int i = 0; i < depth; ++i) {
        cout << "  ";
    }
    cout << name << " (" << size << " bytes)" << endl;
}
FileSystemItem* clone() const override {
    return new File(*this); 
}