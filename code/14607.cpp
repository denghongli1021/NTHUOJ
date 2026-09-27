#include "14607.h"
#include <iostream>
#include <string>

// #define DEBUG 

#ifdef DEBUG
#include <chrono>
#include <cstdio>
#endif

int main(){
#ifdef DEBUG
    freopen("testcase/example.in", "r", stdin);
    freopen("testcase/example.out", "w+", stdout);
    auto start = std::chrono::high_resolution_clock::now();
#endif

    // Initialize Git
    Git git;

    // Testcases
    int t;
    std::cin >> t;
    // Iterate
    while(t--){
        std::string cmd1, cmd2;
        std::cin >> cmd1 >> cmd2;
        if (cmd2 == "switch") {
            int idx;
            std::cin >> idx;
            git.Switch(idx);
        }
        else if (cmd2 == "commit") {
            int total_files;
            Commit* commit = new Commit();
            
            std::cin >> total_files;
            while(total_files--) {
                std::string filename;
                int nInsertion, nDeletion;
                std::cin >> filename >> nInsertion >> nDeletion;
                // Buffer
                int idx_buffer;
                std::string line_buffer;
                Commit::FileChange fileChange(filename);
                // Scan the insertion
                for (int i = 0; i < nInsertion; i++) {
                    std::cin >> idx_buffer;
                    std::getline(std::cin, line_buffer);
                    line_buffer = line_buffer.substr(1);
                    fileChange.addInsertion(idx_buffer, line_buffer);
                }
                // Scan the deletion
                for (int i = 0; i < nDeletion; i++) {
                    std::cin >> idx_buffer;
                    fileChange.addDeletion(idx_buffer, "");
                }
                // Push to the commit
                commit->Insert(fileChange);
            }
            git.CreateCommit(commit);
        }
        else if (cmd2 == "open") {
            std::string filename;
            std::cin >> filename;
            auto file = git.Open(filename);
            for(const auto& line : file) {
                std::cout << line << std::endl;
            }
        }
    }

#ifdef DEBUG
    auto end = std::chrono::high_resolution_clock::now();

    fclose(stdin);
    fclose(stdout);

    freopen("/dev/tty", "r", stdin);
    freopen("/dev/tty", "w", stdout);

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << duration.count() << " ms\n";
#endif
}
