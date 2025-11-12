#ifndef FILE_H
#define FILE_H

#include "FileSystemItem.h"

class File: public FileSystemItem{
    File(const string& name, long size) : FileSystemItem(name, size) {}
    
    long getSize() const override {
        return size;
    }

    void display(int depth = 0) const override;
    FileSystemItem* clone() const override;


}
#endif // FILE_H