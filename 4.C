#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Structure for a node in the binary search tree
struct TreeNode {
    char buildingName[50];
    double distance;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode* createNode(char name[], double distance) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    strcpy(newNode->buildingName, name);
    newNode->distance = distance;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary search tree
struct TreeNode* insertNode(struct TreeNode* root, char name[], double distance) {
    if (root == NULL) {
        return createNode(name, distance);
    }

    if (distance < root->distance) {
        root->left = insertNode(root->left, name, distance);
    } else {
        root->right = insertNode(root->right, name, distance);
    }

    return root;
}

// Function to perform Depth-First Search (DFS) and print building names
void DFS(struct TreeNode* root) {
    if (root != NULL) {
        printf("%s\n", root->buildingName);
        DFS(root->left);
        DFS(root->right);
    }
}

// Function to perform Breadth-First Search (BFS) and print building names
void BFS(struct TreeNode* root) {
    if (root == NULL) return;

    // Implement BFS using a queue (not included in this example)

    printf("%s\n", root->buildingName);

    BFS(root->left);
    BFS(root->right);
}

// Function to find the minimum node in the tree
struct TreeNode* findMinimumNode(struct TreeNode* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    double playerLat, playerLong;
    scanf("%lf %lf", &playerLat, &playerLong);

    struct TreeNode* root = NULL;

    for (int i = 0; i < n; ++i) {
        char buildingName[50];
        double buildingLat, buildingLong;
        scanf("%s %lf %lf", buildingName, &buildingLat, &buildingLong);

        // Calculate distance between player and building using Haversine formula (not included in this example)

        double distance = /* Calculate distance between player and building */;
        root = insertNode(root, buildingName, distance);
    }

    // Perform DFS
    printf("DFS:\n");
    DFS(root);

    // Perform BFS
    printf("BFS:\n");
    BFS(root);

    // Find the closest building (minimum node)
    struct TreeNode* minNode = findMinimumNode(root);
    printf("Path from Root to Minimum Node:\n");

    // Print path from root to minimum node
    while (root != NULL && root != minNode) {
        printf("%s\n", root->buildingName);
        if (minNode->distance < root->distance) {
            root = root->left;
        } else {
            root = root->right;
        }
    }

    // Print nearest treasure found
    printf("Nearest Treasure Found: %s (Distance: %.1lf)\n", minNode->buildingName, minNode->distance);

    return 0;
}
