# Cyber-Classroom-Killer
Currently, only 2 software blockades are supported, and will be produced gradually in the future.  
principle:  
```cpp
void searchAndOpen(const std::string& folderPath, const std::string& fileName, int& numFilesSearched) {
    std::string searchPath = folderPath + "\\*.*";
    WIN32_FIND_DATA findData;
    HANDLE hFind = FindFirstFile(searchPath.c_str(), &findData);

    if (hFind == INVALID_HANDLE_VALUE) {
    	return;
    }

    do {
        if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            if (strcmp(findData.cFileName, ".") != 0 && strcmp(findData.cFileName, "..") != 0) {
                std::string subFolderPath = folderPath + "\\" + findData.cFileName;
                searchAndOpen(subFolderPath, fileName, numFilesSearched);
            }
        } else {
            numFilesSearched++;

            if (strcmp(findData.cFileName, fileName.c_str()) == 0) {
                std::string filePath = folderPath + "\\" + fileName;
                ShellExecute(NULL, "open", filePath.c_str(), NULL, NULL, SW_SHOWNORMAL);
                return;
            }
        }

        if (numFilesSearched % 1000 == 0) {
            float progress = static_cast<float>(numFilesSearched) / 1000000.0f * 100.0f;  // Assumes around 1 million files on C:
            cout << "Scanning for files to open, progress: " << progress << "%\r" << flush;
        }
    } while (FindNextFile(hFind, &findData));

    FindClose(hFind);
}
```
Find the location of the blocked file,and display the search progress.  
Assumes around 1 million files on C: ,Find 1000 files per unit.  

```cpp
void opent() {
	system("taskkill /im Student.exe");
    int numFilesSearched = 0;
	searchAndOpen("C:", "Teacher.exe", numFilesSearched);
	if(numFilesSearched == 0){
    	cout <<endl<< "no files found！" << endl;
	}
	else{
		cout<<endl<<"Done, select your action         "<<endl;
	}
}
```
Find the exe file named Teacher located at C:,if not found, output ' no files found! '.
