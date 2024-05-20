//C program to autometically move files from one folder to another folder

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>

int main()
{
    FILE *sourceFile;
    FILE *destinationFile;
    DIR *sourcefolder;
    DIR *destinationfolder;
    char *sfolder;
    char *dfolder;
    struct dirent *file;
    FILE *openFile;
    FILE *filePointer;
    char buffer[100];

    // sourcefolder = opendir("C:/Users/MY PC/Desktop/code/C/Ccode/myPrograms/from");
    // destinationfolder = opendir("C:/Users/MY PC/Desktop/code/C/Ccode/myPrograms/to");
    // sfolder = "C:/Users/MY PC/Desktop/code/C/Ccode/myPrograms/from";
    // dfolder = "C:/Users/MY PC/Desktop/code/C/Ccode/myPrograms/to";

    sourcefolder = opendir("C:/Users/MY PC/Desktop");
    destinationfolder = opendir("C:/Users/MY PC/Desktop/pdfFiles");
    sfolder = "C:/Users/MY PC/Desktop";
    dfolder = "C:/Users/MY PC/Desktop/pdfFiles";

    printf("Extentions found: \n");

    if (sourcefolder == NULL)
    {
        printf("Unable to read the file\n");
        return 1;
    }
    file = readdir(sourcefolder);

    while ((file = readdir(sourcefolder)) != NULL)
    {

        if (file->d_type == DT_DIR)
        {
            printf("Folders found and skipped\n");
            continue;
        }
        char *ext;
        char *p;
        ext = strchr(file->d_name, '.');
        p = "pdf";
        int extDet = strcmp(p,(ext+1));
        printf("Extentions = %s\n", (ext + 1));

        
        if (file->d_type == DT_REG && !extDet)
        {
            char filePath[1024];
            char destinationPath[1024];
            snprintf(filePath, sizeof(filePath), "%s/%s", sfolder, file->d_name);
            snprintf(destinationPath, sizeof(destinationPath), "%s/%s", dfolder, file->d_name);

            rename(filePath, destinationPath);
        }
    }
    fclose(sourceFile);
    fclose(destinationFile);

    return 0;
}
