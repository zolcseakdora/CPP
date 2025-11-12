#ifndef FILESYSTEMITEM_H
#define FILESYSTEMITEM_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class FileSystemItem {
protected:
    string name; 
    long size;
public:    
    FileSystemItem(const string& name, long size = 0) : name(name), size(size) {}
    virtual ~FileSystemItem() = default;
    virtual long getSize() const = 0; // visszatéríti az elem méretét
    virtual void display(int depth = 0) const = 0; // kiírja az elem tartalmát 
    virtual FileSystemItem* clone() const = 0; // másolatot készít 
    const string& getName() const { return name; }
    friend ostream& operator<<(ostream& os, const FileSystemItem& item) {
        item.display();
        return os;
    }
    bool operator<(const FileSystemItem& other) const {
        return name < other.name;
    }
}
#endif // FILESYSTEMITEM_H