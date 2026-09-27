#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include <list>
#include <string>
#include <iostream>

#define MAX_NODE_SIZE 10005

#include <vector>
#include <stack>
#include <string>
#include <list>

class Commit
{
public:
    struct LineChange
    {
        int index;
        std::string content;
    };

    struct FileChange
    {
        std::string fileName;
        std::list<LineChange> insertions;
        std::list<LineChange> deletions;

        FileChange(std::string name) : fileName(name) {}

        void addInsertion(int index, const std::string &line)
        {
            insertions.push_back((LineChange){index, line});
        }

        void addDeletion(int index, const std::string &line)
        {
            deletions.push_back((LineChange){index, line});
        }
    };

private:
    // Trie Data Structure
    struct TrieNode
    {
        TrieNode *children[26];
        int idx;

        TrieNode()
        {
            idx = -1;
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
        }
    };

    TrieNode *m_root;
    std::vector<Commit::FileChange> m_commits;

public:
    // Init Trie
    Commit()
    {
        m_root = new TrieNode();
    }
    // Destroy Trie
    ~Commit()
    {
        Clear(m_root);
    }
    // Copy Constructor
    Commit(const Commit &) = delete;
    Commit &operator=(const Commit &) = delete;

    void Clear(TrieNode *node);                               // TODO: Clear a tree by given root node
    int Insert(FileChange fileChange);                        // TODO: Insert a file change to a commit
    const Commit::FileChange *Search(const std::string &str); // TODO: retrun the address of the FileChange, given string name
};

class GitNode
{
private:
    std::vector<int> children; // Childerns of the node
    int parent;                // Parent of the node
    int level;                 // Level of that node in that tree
    Commit *commit;            // Commit content
public:
    GitNode() : parent(-1), level(-1), commit(nullptr) {}
    GitNode(int p, int l) : parent(p), level(l), commit(nullptr) {}
    GitNode(int p, int l, Commit *c) : parent(p), level(l), commit(c) {}

    friend class Git;
};

class Git
{
private:
    std::vector<GitNode *> m_gitnodes; // Store every Git
    int m_current;                     // Current branch and commit in (int) index term

public:
    // Constructor
    Git();
    Git(const Git &) = delete;
    Git &operator=(const Git &) = delete;
    // Destructor
    ~Git();

    void Switch(int idx);                                       // TODO: Switch Command
    void CreateCommit(Commit *commit);                          // TODO: Commit Command
    std::vector<std::string> Open(const std::string &filename); // TODO: Git Open
};
// Commit class implementation
void Commit::Clear(TrieNode *node)
{
    if (node == nullptr)
        return;

    // Recursively delete all children nodes
    for (int i = 0; i < 26; i++)
    {
        if (node->children[i] != nullptr)
        {
            Clear(node->children[i]);
        }
    }

    // Delete the current node
    delete node;
}

int Commit::Insert(FileChange fileChange)
{
    // Start from root of trie
    TrieNode *current = m_root;

    // Insert the filename character by character into the trie
    for (char c : fileChange.fileName)
    {
        int index = c - 'a'; // Convert to 0-25 index

        // Create a new node if it doesn't exist
        if (current->children[index] == nullptr)
        {
            current->children[index] = new TrieNode();
        }

        // Move to the next node
        current = current->children[index];
    }

    // Set the index to the size of m_commits
    current->idx = m_commits.size();

    // Add the file change to the vector
    m_commits.push_back(fileChange);

    return current->idx;
}

const Commit::FileChange *Commit::Search(const std::string &str)
{
    // Start from root of trie
    TrieNode *current = m_root;

    // Traverse the trie based on the characters in str
    for (char c : str)
    {
        int index = c - 'a'; // Convert to 0-25 index

        // If the node doesn't exist, the file doesn't exist
        if (current->children[index] == nullptr)
        {
            return nullptr;
        }

        // Move to the next node
        current = current->children[index];
    }

    // If idx is -1, file doesn't exist
    if (current->idx == -1)
    {
        return nullptr;
    }

    // Return the file change at the index
    return &m_commits[current->idx];
}

// Git class implementation
Git::Git()
{
    // Initialize with root node
    m_gitnodes.push_back(new GitNode(-1, 0, new Commit()));
    m_current = 0;
}

Git::~Git()
{
    // Free all git nodes
    for (auto node : m_gitnodes)
    {
        delete node->commit;
        delete node;
    }
}

void Git::Switch(int idx)
{
    // Switch to the specified node
    m_current = idx;
    std::cout << "Switched to Branch " << idx << std::endl;
}

void Git::CreateCommit(Commit *commit)
{
    // Create a new git node with the given commit
    GitNode *current = m_gitnodes[m_current];
    int newIdx = m_gitnodes.size();

    // Create a new node with parent as current, level +1, and the given commit
    GitNode *newNode = new GitNode(m_current, current->level + 1, commit);

    // Add the new node to the vector
    m_gitnodes.push_back(newNode);

    // Add the new node's index to current node's children
    current->children.push_back(newIdx);

    // Update current node to the new node
    m_current = newIdx;
}

std::vector<std::string> Git::Open(const std::string &filename)
{
    std::vector<std::string> fileContents;
    std::stack<int> path;
    int current = m_current;

    // Traverse from current node to root collecting nodes
    while (current != -1)
    {
        path.push(current);
        current = m_gitnodes[current]->parent;
    }

    // Process each node from root to current
    while (!path.empty())
    {
        int idx = path.top();
        path.pop();

        GitNode *node = m_gitnodes[idx];
        if (node->commit == nullptr)
            continue;

        // Search for the file in this commit
        const Commit::FileChange *fileChange = node->commit->Search(filename);
        if (fileChange == nullptr)
            continue;

        // Process insertions
        for (const Commit::LineChange &insertion : fileChange->insertions)
        {
            // Make sure we have enough lines
            while (fileContents.size() <= insertion.index)
            {
                fileContents.push_back("");
            }
            fileContents[insertion.index] = insertion.content;
        }

        // Process deletions
        for (const Commit::LineChange &deletion : fileChange->deletions)
        {
            // Make sure the index is valid
            if (deletion.index < fileContents.size())
            {
                // Remove the line by replacing with empty content
                fileContents[deletion.index] = "";
            }
        }

        // Remove empty lines (those that were deleted)
        std::vector<std::string> nonEmptyLines;
        for (const std::string &line : fileContents)
        {
            if (!line.empty())
            {
                nonEmptyLines.push_back(line);
            }
        }
        fileContents = nonEmptyLines;
    }

    return fileContents;
}
#endif