#include <iostream>

struct Pembeli {
    int nomor;
    // Tambahkan data pembeli lainnya sesuai kebutuhan
};

void binaryInsertionSort(Pembeli arr[], int n) {
    for (int i = 1; i < n; i++) {
        Pembeli key = arr[i];
        int left = 0, right = i - 1;

        // Cari posisi tempat untuk menyisipkan kunci
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid].nomor > key.nomor) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        // Pindahkan elemen-elemen yang lebih besar satu posisi ke kanan
        for (int j = i - 1; j >= left; j--) {
            arr[j + 1] = arr[j];
        }

        // Tempatkan kunci di posisi yang sesuai
        arr[left] = key;
    }
}

void printQueue(Pembeli arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << "Nomor Antrian Pembeli: " << arr[i].nomor << " ";
        // Tambahkan output data pembeli lainnya sesuai kebutuhan
        std::cout << std::endl;
    }
}

int main() {
    const int jumlahPembeli = 5; // Ganti jumlah pembeli sesuai kebutuhan
    Pembeli antrian[jumlahPembeli];

    // Input data pembeli
    for (int i = 0; i < jumlahPembeli; i++) {
        std::cout << "Masukkan nomor antrian pembeli ke-" << i + 1 << ": ";
        std::cin >> antrian[i].nomor;
        // Tambahkan input data pembeli lainnya sesuai kebutuhan
    }

    // Menampilkan antrian sebelum diurutkan
    std::cout << "\nAntrian Pembeli Sebelum Diurutkan:\n";
    printQueue(antrian, jumlahPembeli);

    // Mengurutkan antrian
    binaryInsertionSort(antrian, jumlahPembeli);

    // Menampilkan antrian setelah diurutkan
    std::cout << "\nAntrian Pembeli Setelah Diurutkan:\n";
    printQueue(antrian, jumlahPembeli);

    return 0;
}
