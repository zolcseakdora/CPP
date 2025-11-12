#include "Directory.h"
#include <algorithm>
#include "FileSystemItem.h"
#include <iostream>

using namespace std;

Directory::Directory(const string& name) 
    : FileSystemItem(name) {}

Directory::~Directory() {
    cleanup();
}

// Mély másolás segéd
void Directory::deepCopy(const Directory& other) {
    for (const auto& item : other.children) {
        children.push_back(item->clone()); 
    }
}

// Felszabadítás segéd
void Directory::cleanup() {
    for (auto& item : children) {
        delete item; 
    }
    children.clear();
}

// Másoló Konstruktor (Deep Copy)
Directory::Directory(const Directory& other) 
    : FileSystemItem(other.name, other.size) {
    deepCopy(other);
}

// Értékadó Operátor (Deep Copy)
Directory& Directory::operator=(const Directory& other) {
    if (this != &other) {
        cleanup(); 
        name = other.name;
        size = other.size;
        deepCopy(other); 
    }
    return *this;
}

void Directory::add(FileSystemItem* item) {
    if (item) {
        children.push_back(item);
    }
}

void Directory::remove(const string& name) {
    auto it = std::remove_if(children.begin(), children.end(), 
        [&name](FileSystemItem* item) {
            if (item && item->getName() == name) {
                delete item; 
                return true;
            }
            return false;
        });
    children.erase(it, children.end());
}

FileSystemItem* Directory::find(const string& name) {
    for (FileSystemItem* item : children) {
        if (item->getName() == name) {
            return item;
        }
        if (Directory* dir = dynamic_cast<Directory*>(item)) {
            if (FileSystemItem* found = dir->find(name)) {
                return found;
            }
        }
    }
    return nullptr;
}

long Directory::getSize() const {
    long totalSize = 0;
    for (const auto& item : children) {
        if (item) {
            totalSize += item->getSize();
        }
    }
    return totalSize;
}

void Directory::display(int depth) const {
    for (int i = 0; i < depth; ++i) {
        cout << "  ";
    }
    cout << name << "/ (" << getSize() << " bytes)" << endl; 

    for (const auto& item : children) {
        if (item) {
            item->display(depth + 1);
        }
    }
}

FileSystemItem* Directory::clone() const {
    return new Directory(*this); 
}

// Operátorok
Directory& Directory::operator+=(FileSystemItem* item) {
    add(item);
    return *this;
}

Directory& Directory::operator-=(const string& name) {
    remove(name);
    return *this;
}