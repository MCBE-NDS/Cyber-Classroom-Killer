#include <windows.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstdlib>
#include <tchar.h>
#include <string>
#include <io.h>

using namespace std;

void searchAndOpen(const std::string& folderPath, const std::string& fileName, int& numFilesSearched) {
    std::string searchPath = folderPath + "\\*.*";
    WIN32_FIND_DATA findData;
    HANDLE hFind = FindFirstFile(searchPath.c_str(), &findData);

    if (hFind == INVALID_HANDLE_VALUE) {
    	return;
    }

    do {
        if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            // Ignore directories "." and ".."
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

        // Update progress every 1000 files
        if (numFilesSearched % 1000 == 0) {
            float progress = static_cast<float>(numFilesSearched) / 1000000.0f * 100.0f;  // Assumes around 1 million files on C:
            std::cout << "正在扫描要打开的文件,进度: " << progress << "%\r" << std::flush;
        }
    } while (FindNextFile(hFind, &findData));

    FindClose(hFind);
}

void opent() {
	system("taskkill /im Student.exe");
    int numFilesSearched = 0;
	searchAndOpen("C:", "Teacher.exe", numFilesSearched);
	if(numFilesSearched == 0){
    	cout <<endl<< "大哥，没有文件啊！" << endl;
	}
	else{
		cout<<endl<<"执行完毕，选择您的操作        "<<endl;
	}
}



void opens() {
    int numFilesSearched = 0;
    searchAndOpen("C:", "Student.exe", numFilesSearched);
    if(numFilesSearched == 0){
    	cout <<endl<< "大哥，没有文件啊！" << endl;
	}
	else{
		cout<<endl<<"执行完毕，选择您的操作        "<<endl;
	}
}

int main(){
	int a;
	char b[7];
	b[0]=0;
	b[1]=1;
	b[2]=1;
	b[3]=4;
	b[4]=5;
	b[5]=1;
	b[6]=9;
	system("color 2");
    cout<<"By NDS STUDIO MC_BE" << endl;
    cout<<"=================================================================================="<<endl;
	cout<<" __  __  ____    ____        ____    ______  __  __  ____    ______   _____      "<<endl;
	cout<<"/\\ \\/\\ \\/\\  _`\\ /\\  _`\\     /\\  _`\\ /\\__  _\\/\\ \\/\\ \\/\\  _`\\ /\\__  _\\ /\\  __`\\    "<<endl;
	cout<<"\\ \\ `\\\\ \\ \\ \\/\\ \\ \\,\\L\\_\\   \\ \\,\\L\\_\\/_/\\ \\/\\ \\ \\ \\ \\ \\ \\/\\ \\/_/\\ \\/ \\ \\ \\/\\ \\  "<<endl;
	cout<<" \\ \\ , ` \\ \\ \\ \\ \\/_\\__ \\    \\/_\\__ \\  \\ \\ \\ \\ \\ \\ \\ \\ \\ \\ \\ \\ \\ \\ \\  \\ \\ \\ \\ \\  "<<endl;
	cout<<"  \\ \\ \\`\\ \\ \\ \\_\\ \\/\\ \\L\\ \\    /\\ \\L\\ \\ \\ \\ \\ \\ \\ \\_\\ \\ \\ \\_\\ \\ \\_\\ \\__\\ \\ \\_\\ \\ "<<endl;
	cout<<"   \\ \\_\\ \\_\\ \\____/\\ `\\____\\   \\ `\\____\\ \\ \\_\\ \\ \\_____\\ \\____/ /\\_____\\\\ \\_____\\"<<endl;
	cout<<"    \\/_/\\/_/\\/___/  \\/_____/    \\/_____/  \\/_/  \\/_____/\\/___/  \\/_____/ \\/_____/"<<endl;
	cout<<"==================================================================================="<<endl;
    cout<<"请稍后" <<endl;
    cout<<"================================================================================"<<endl;
    cout<<"免责声明："<<endl;
    cout<<"1.请勿使用本软件扰乱课堂纪律(指用本软件做出一些不正当行为)，后果自负。"<<endl;
    cout<<"2.请勿非法传播此软件，后果自负。"<<endl;
    cout<<"3.出现的任何事故都不由作者本人及其工作室负责。"<<endl;
    cout<<"================================================================================"<<endl;
    asd1:cout<<"按1关闭学生端并打开教师端" << endl;
	cout<<"按2关闭学生端并打开教师端且连续关闭学生端" << endl;
	cout<<"按3连续关闭学生端" << endl;
	cout<<"按4打开学生端" <<endl;
	cout<<"按5打开教师端"<<endl;
	cout<<"按6退出"<<endl;
	cout<<"推荐使用2和3"<<endl;
	cout<<"连续关闭可能会报错，不要担心"<<endl;
	cout<<"连续关闭时请保持程序运行"<<endl;
	asd:cin >> a;
	switch(a){
		case 1:
			cout<<"请稍后"<<endl;
			system("taskkill /im Student.exe");
			opent();
			system("taskkill /im Student.exe");
    		goto asd1;
			break;
		case 2:
			cout<<"请稍后"<<endl;
			system("taskkill /im Student.exe"); // kill Student process
    		opent();
			for (int i = 0 ; i >= 0 ; i++)
			{
				system("taskkill /im Student.exe"); // kill Student process
			}
			break;
		case 3:
			cout<<"请稍后"<<endl;
			for (int i = 0 ; i >= 0 ; i++)
			{
				system("taskkill /im Student.exe"); // kill Student process
			}
			break;
		case 4:
			cout<<"请稍后"<<endl;
    		opens();
    		goto asd1;
    		break;
    	case 5:
			cout<<"请稍后"<<endl;
    		opent();
    		goto asd1;
    		break;
    	case 6:
    		return 0;
    		break;
    	default:
    		cout<<"宁 可 别 给 电 脑 输 奇 怪 的 东 西 啊 ！ ！"<<endl;
			cout<<"没有精神，重来！！"<<endl;
			goto asd;
			break;
	}
	system ("pause");
}
