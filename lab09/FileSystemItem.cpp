#include "FileSystemItem.h"
#include <numeric>

using namespace std;


FileSystemItem::FileSystemItem(const string& name, long size) 
    : name(name), size(size) {}

ostream& operator<<(ostream& os, const FileSystemItem& item) {
    item.display();
    return os;
}

bool FileSystemItem::operator<(const FileSystemItem& other) const {
    return name < other.name;
}