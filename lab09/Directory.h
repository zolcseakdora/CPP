#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "FileSystemItem.h"
#include <vector>

class Directory : public FileSystemItem {
private:
    vector<FileSystemItem*> children; 

    void deepCopy(const Directory& other);
    void cleanup();

public:
    Directory(const string& name);
    ~Directory() override;

    Directory(const Directory& other);
    Directory& operator=(const Directory& other);

    void add(FileSystemItem* item);
    void remove(const string& name);
    FileSystemItem* find(const string& name);

    long getSize() const override;
    void display(int depth = 0) const override;
    FileSystemItem* clone() const override;

    Directory& operator+=(FileSystemItem* item);
    Directory& operator-=(const string& name);
};
#endif // DIRECTORY_H