#include <stdbool.h>
#include "Parameters.h"

typedef struct Inode{
    //File owner identifer: individual owner
    char* fileOwner[FILE_OWNER_LENGTH];

    //File owner identifer: group
    char OwnerGroup[FILE_OWNER_LENGTH];

    //File type: regular '-', directory 'd', character device file 'c', block device file 'b'
    //local socket file 's', FIFO (pipes) 'p', symbolic link 'l'.
    char fileType;

    //File access permissions: Three classes -- the owner, the group owner and other users.
    //The access rights for each of the three classes can be set individually: read, write and execute
    //Execution permission for a directory gives the right to search the directory for a file name
    bool ownerPermission[PERMISSION_CAT_NUM];
    bool groupPermission[PERMISSION_CAT_NUM];
    bool otherPermission[PERMISSION_CAT_NUM];

    //File access times: the time the file was last modified, when it was last accessed
    //and when the inode was last modified
    size_type fileModifiedTime;
    size_type fileAccessTime;
    size_type inodeModifiedTime;

    //Number of links to the file: The number of names the file has in the directory hierarchy
    size_type numOfLinks;

    //Table of contents for the disk addresses of data in a file
    addr_type directBlock[DIRECT_BLOCK_NUM];
    addr_type singleBlock;
    addr_type doubleBlock;
    addr_type tripleBlock;

    //File size -- It is 1 greater than the highest byte offset of data in the file
    size_type fileSize;
} Inode;
