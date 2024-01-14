#include <iostream>
using namespace std;

struct node {
    char data;
    node *kiri;
    node *kanan;
};

node *akar = NULL;

void addNode(node **akar, char isi) {
    if ((*akar) == NULL) {
        node *baru;
        baru = new node;
        baru->data = isi;
        baru->kiri = NULL;
        baru->kanan = NULL;
        (*akar) = baru;
    }
}

node* searchNode(node *akar, char target) {
    if (akar == NULL || akar->data == target) {
        return akar;
    }

    if (target < akar->data) {
        return searchNode(akar->kiri, target);
    }

    return searchNode(akar->kanan, target);
}

void preOrder(node *akar) {
    if (akar != NULL) {
        cout << akar->data << " ";
        preOrder(akar->kiri);
        preOrder(akar->kanan);
    }
}

void inOrder(node *akar) {
    if (akar != NULL) {
        inOrder(akar->kiri);
        cout << akar->data << " ";
        inOrder(akar->kanan);
    }
}

void postOrder(node *akar) {
    if (akar != NULL) {
        postOrder(akar->kiri);
        postOrder(akar->kanan);
        cout << akar->data << " ";
    }
}

int main() {
    char abjad;
    cout << "\n\n\tPosisi Awal Tree:\n\n";
    cout << "\t       R\n\t      / \\\n\t     A   E\n\t    / \\   \\\n\t   S   F   B\n\t / \\     / \\\n\t I   T   D   C\n\n";
    addNode(&akar, abjad = 'R');
    addNode(&akar->kiri, abjad = 'A');
    addNode(&akar->kanan, abjad = 'E');
    addNode(&akar->kiri->kiri, abjad = 'S');
    addNode(&akar->kiri->kanan, abjad = 'F');
    addNode(&akar->kanan->kanan, abjad = 'B');
    addNode(&akar->kanan->kanan->kiri, abjad = 'D');
    addNode(&akar->kanan->kanan->kanan, abjad = 'C');
    addNode(&akar->kiri->kiri->kiri, abjad = 'I');
    addNode(&akar->kiri->kiri->kanan, abjad = 'T');

    cout << "Tampilan PreOrder : ";
    preOrder(akar);
    cout << "\nTampilan InOrder   : ";
    inOrder(akar);
    cout << "\nTampilan PostOrder : ";
    postOrder(akar);

    return 0;
}
