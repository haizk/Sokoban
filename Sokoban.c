#include <stdio.h>
//Hezkiel Bram Setiawan M0521030
//Responsi 1

void swap(char *, char *);
void play(char *, int, int, char *, int *, int *);
void outsideLevel(int, char *, int *);
void levelSelector(char *, int *);
void insideShop(int, char *, int *);
void shop(char *, int *);
void tutorial();
void mainMenu();

int main() {
	printf("Selamat datang di Haizk Sokoban!\n");
	mainMenu();
	printf("\nSelamat tinggal!");
    return 0;
}

void mainMenu() {
	char database[7] = {'#', '$', 'X', 'Y', 'O', '@', ' '};
	int input, uang = 0;
	while("M0521030") {
		printf("\nMENU UTAMA\n1. Main Sokoban\n2. Toko\n3. Tutorial\n0. Keluar\nMasukkan pilihan: ");
		fflush(stdin);
		if(!scanf("%d", &input)) {
			printf("\n\aPilih dengan benar!\n");
			continue;
		}
		if(input == 0) {
			while("M0521030") {
				printf("\nApakah anda yakin ingin keluar?\n1. Ya\n0. Tidak\nMasukkan pilihan: ");
				fflush(stdin);
				if(!scanf("%d", &input)) {
					printf("\n\aPilih dengan benar!\n");
					continue;
				}
				if(input == 1) return;
				else if(input == 0) break;
				else printf("\n\aPilih dengan benar!\n");
			}
			continue;
		}
		switch(input) {
			case 1:
				levelSelector(database, &uang);
				break;
			case 2:
				shop(database, &uang);
				break;
			case 3:
				tutorial();
				break;
			case 0x0521030:
				printf("\n\n\auwaw apaan nih! nih hawtokwen +500 buwat kamwuh\n\n");
				uang += 500;
				break;
			default:
				printf("\n\aPilih dengan benar!\n");
				break;
		}
	}
}

void tutorial() {
	printf("\nTUTORIAL");
	printf("\nInput A untuk bergerak ke kiri\nInput S untuk bergerak ke bawah\nInput D untuk bergerak ke kanan\nInput W untuk bergerak ke atas");
	printf("\nInput R untuk restart\nInput Z untuk undo\nInput X untuk keluar dari level");
	printf("\nInput selain input di atas tidak akan mengubah apapun");
	printf("\nMaksimal gerakan yang dapat dilakukan dalam satu level adalah 999 gerakan");
	printf("\nIndikasi jumlah gerakan terdapat pada angka kanan bawah level");
	printf("\nAnda tidak dapat bergerak melewati dinding, mendorong box melewati dinding, dan mendorong box melewati box");
	printf("\nLevel akan selesai apabila semua box berada pada tujuan\nSecara default:");
	printf("\nDinding = #\nTujuan = $\nBox = X\nBox tepat pada tujuan = Y\nPlayer = O\nPlayer tepat pada tujuan = @\n");
}

void shop(char *database, int *uang) {
	int input;
    while("M0521030") {
        printf("\nTOKO (Hatoken: %d)\n1. Dinding\n2. Tujuan\n3. Box\n4. Box tepat pada tujuan\n5. Player\n6. Player tepat pada tujuan\n0. Keluar dari toko\nMasukkan pilihan: ", *uang);
        fflush(stdin);
        if(!scanf("%d", &input)) {
            printf("\n\aPilih dengan benar!\n");
            continue;
        }
        if(input == 0) return;
		else if(input >= 1 && input <= 6) insideShop(input, database, uang);
		else printf("\n\aPilih dengan benar!\n");
    }
}

void insideShop(int terpilih, char *database, int *uang) {
	char namaDatabase[6][30] = {"Dinding", "Tujuan", "Box", "Box tepat pada tujuan", "Player", "Player tepat pada tujuan"};
	char upperDatabase[6][30] = {"DINDING", "TUJUAN", "BOX", "BOX TEPAT PADA TUJUAN", "PLAYER", "PLAYER TEPAT PADA TUJUAN"};
	char lowerDatabase[6][30] = {"dinding", "tujuan", "box", "box tepat pada tujuan", "player", "player tepat pada tujuan"};
	char daftar[6][5] = {
		{'#', '=', '\\', '/', '&'},
		{'$', '*', '^', 'V', ':'},
		{'X', 'D', 'Z', '8', '?'},
		{'Y', 'B', 'K', '6', '!'},
		{'O', 'P', 'A', 'H', '~'},
		{'@', '%', '+', '.', '-'},
	};
	int input, konfirmasi, harga[5] = {10, 20, 30, 40, 50};
	while("M0521030") {
		printf("\nTOKO %s (Hatoken: %d)\n%s saat ini: %c\n", upperDatabase[terpilih-1], *uang, namaDatabase[terpilih-1], *(database+terpilih-1));
		for(int x=0; x<5; x++) printf("%d. %c (%d Hatoken)\n", x+1, daftar[terpilih-1][x], harga[x]);
		printf("0. Keluar dari toko %s\nMasukkan pilihan: ", lowerDatabase[terpilih-1]);
		fflush(stdin);
		if(!scanf("%d", &input)) {
			printf("\n\aPilih dengan benar!\n");
			continue;
		}
		if(input == 0) return;
		else if(input >= 1 && input <= 5) {
			if(*(database+terpilih-1) != daftar[terpilih-1][input-1] && *uang >= harga[input-1]) {
				while("M0521030") {
					printf("\nApakah anda yakin untuk membeli %s %c dengan harga %d Hatoken?\n1. Ya\n0. Tidak\nMasukkan pilihan: ", lowerDatabase[terpilih-1], daftar[terpilih-1][input-1], harga[input-1]);
					fflush(stdin);
					if(!scanf("%d", &konfirmasi)) {
						printf("\n\aPilih dengan benar!\n");
						continue;
					}
					if(konfirmasi == 1) {
						*uang -= harga[input-1];
						*(database+terpilih-1) = daftar[terpilih-1][input-1];
						printf("\nSelamat! Anda membeli %s %c\n", lowerDatabase[terpilih-1], daftar[terpilih-1][input-1]);
						break;
					} else if(konfirmasi == 0) {
						printf("\nAnda tidak jadi membeli %s %c\n", lowerDatabase[terpilih-1], daftar[terpilih-1][input-1]);
						break;
					} else printf("\n\aPilih dengan benar!\n");
				}
			} else if(*(database+terpilih-1) == daftar[terpilih-1][input-1]) {
				printf("\n\a%s anda sudah %c\n", namaDatabase[terpilih-1], *(database+terpilih-1));
			} else if(*uang < harga[input-1]) printf("\n\aHatoken anda tidak cukup\n");
		} else printf("\n\aPilih dengan benar!\n");
	}
}

void levelSelector(char *database, int *uang) {
	int input;
	while("M0521030") {
		printf("\nPILIH LEVEL");
		for(int x=1; x<=20; x++) printf("\n%2d. Level %d", x, x);
		for(int x=21; x<=23; x++) printf("\n%d. Spesial %d", x, x-20);
		printf("\n 0. Keluar\nMasukkan pilihan: ");
		fflush(stdin);
		if(!scanf("%d", &input)) {
			printf("\n\aPilih dengan benar!\n");
			continue;
		}
		if(input == 0) return;
		else if(input >= 1 && input <= 23) {
			outsideLevel(input-1, database, uang);
			return;
		} else printf("\n\aPilih dengan benar!\n");
	}
}

void outsideLevel(int indikasiLevel, char *database, int *uang) {
	int indikasiSelesai = 0, bonus, jumlahGerakan;
	while("M0521030") {
		jumlahGerakan = 0;
		char arena[23][20][20] = {
			{ //Level 1
				{"######"},
				{"#   O#"},
				{"#X####"},
				{"# #   "},
				{"#$#   "},
				{"###   "}
			}, { //Level 2
				{"####  "},
				{"#  ###"},
				{"# XX #"},
				{"#$$$ #"},
				{"# OX #"},
				{"#   ##"},
				{"##### "}
			}, { //Level 3
				{"##### "},
				{"# O # "},
				{"#$$$# "},
				{"#XXX##"},
				{"#    #"},
				{"#    #"},
				{"######"}
			}, { //Level 4
				{" ####  "},
				{" #  ###"},
				{" # XX #"},
				{"##$$$ #"},
				{"#  OX #"},
				{"#   ###"},
				{"#####  "}
			}, { //Level 5
				{"  ####   "},
				{"###  ####"},
				{"#       #"},
				{"#OXYYY$ #"},
				{"#       #"},
				{"#########"}
			}, { //Level 6
				{"####  "},
				{"# $#  "},
				{"#  ###"},
				{"#YO  #"},
				{"#  X #"},
				{"#  ###"},
				{"####  "}
			}, { //Level 7
				{"#####  "},
				{"#   #  "},
				{"# O #  "},
				{"# XX###"},
				{"##$ $ #"},
				{" #    #"},
				{" ######"}
			}, { //Level 8
				{"  #####"},
				{"  #   #"},
				{"###XXO#"},
				{"#   ###"},
				{"#     #"},
				{"# $ $ #"},
				{"#######"}
			}, { //Level 9
				{" ####  "},
				{"##  ###"},
				{"#     #"},
				{"#$YYXO#"},
				{"#   ###"},
				{"##  #  "},
				{" ####  "}
			}, { //Level 10
				{"#####  "},
				{"#   ## "},
				{"# #  # "},
				{"#OXY$##"},
				{"##  $ #"},
				{" # X# #"},
				{" ##   #"},
				{"  #####"}
			}, { //Level 11
				{"########"},
				{"#   $$ #"},
				{"#  OXX #"},
				{"##### ##"},
				{"   #  # "},
				{"   #  # "},
				{"   #  # "},
				{"   #### "}
			}, { //Level 12
				{" #####"},
				{" # O #"},
				{" #   #"},
				{"###X #"},
				{"# $$$#"},
				{"# XX #"},
				{"###  #"},
				{"  ####"}
			}, { //Level 13
				{" ##### "},
				{"##$ $##"},
				{"# Y Y #"},
				{"#  #  #"},
				{"# X X #"},
				{"## O ##"},
				{" ##### "}
			}, { //Level 14
				{"#####  "},
				{"#   ###"},
				{"#$ $  #"},
				{"#   # #"},
				{"## #  #"},
				{" #OXX #"},
				{" #    #"},
				{" #  ###"},
				{" ####  "}
			}, { //Level 15
				{"#######  "},
				{"#     ###"},
				{"#  OXX$$#"},
				{"#### ## #"},
				{"  #     #"},
				{"  #  ####"},
				{"  #  #   "},
				{"  ####   "}
			}, { //Level 16
				{"###### "},
				{"#   $# "},
				{"# ## ##"},
				{"#  XXO#"},
				{"# #   #"},
				{"#$  ###"},
				{"#####  "}
			}, { //Level 17
				{"#######"},
				{"#  Y  #"},
				{"#     #"},
				{"## # ##"},
				{" #XO$# "},
				{" #   # "},
				{" ##### "}
			}, { //Level 18
				{"#######"},
				{"#     #"},
				{"#$ $  #"},
				{"# ## ##"},
				{"#  X # "},
				{"###X # "},
				{"  #O # "},
				{"  #  # "},
				{"  #### "}
			}, { //Level 19
				{" #### "},
				{"##  # "},
				{"#$ X# "},
				{"#$X # "},
				{"#$X # "},
				{"#$X # "},
				{"#$ X##"},
				{"#   O#"},
				{"##   #"},
				{" #####"}
			}, { //Level 20
				{"     ##### "},
				{"     #   ##"},
				{"     #    #"},
				{" ######   #"},
				{"##     #$ #"},
				{"# X X O  ##"},
				{"# ######$# "},
				{"#        # "},
				{"########## "}
			}, { //Spesial 1
				{" ########        "},
				{" #  ##  ####     "},
				{" # OX   #  ####  "},
				{" # ##X X   #  #  "},
				{" # ##  #X X   ###"},
				{" # #####  #X X  #"},
				{" # #   ####  #X #"},
				{" # ##     ####  #"},
				{"## $##       # ##"},
				{"#$  $##      # # "},
				{"#$$  $##     # ##"},
				{"###   $#######  #"},
				{"  #  # $        #"},
				{"  ###############"}
			}, { //Spesial 2
				{"#####            "},
				{"#$$$#            "},
				{"#$$$###          "},
				{"#$$   #          "},
				{"#$    #          "},
				{"## #######       "},
				{" # ###O  #####   "},
				{" # ## X#     ##  "},
				{" # # X  ## XX ## "},
				{" # #X   ###  X ##"},
				{" # #  ### ##  X #"},
				{" #   ########X  #"},
				{" #            X #"},
				{" ##  ########  ##"},
				{"  ####      #### "}
			}, { //Spesial 3
				{"#################"},
				{"#     $ $ $ $ $ #"},
				{"#$ # X X X X X  #"},
				{"# X############ #"},
				{"#$ #         #  #"},
				{"# X#         #X #"},
				{"#$ #         # $#"},
				{"# X#         #X #"},
				{"#$ #         # $#"},
				{"# X#         #X #"},
				{"#$ #         # $#"},
				{"# X#         #X #"},
				{"#  #         # $#"},
				{"# ############X #"},
				{"#  X X X X X # $#"},
				{"#O$ $ $ $ $     #"},
				{"#################"}
			}
		};
		int panjangArena[23] = {6, 6, 6, 7, 9, 6, 7, 7, 7, 7, 8, 6, 7, 7, 9, 7, 7, 7, 6, 11, 17, 17, 17};
		int lebarArena[23] = {6, 7, 7, 7, 6, 7, 7, 7, 7, 8, 8, 8, 7, 9, 8, 7, 7, 9, 10, 9, 14, 15, 17};
		int gerakanNormal[23] = {10, 30, 35, 40, 45, 50, 50, 50, 50, 50, 55, 55, 55, 60, 70, 70, 70, 90, 100, 120, 9999, 9999, 9999};
		if(indikasiLevel >= 20) printf("\nSPESIAL %d\n\n", indikasiLevel+1-20);
		else printf("\nLEVEL %d\n\n", indikasiLevel+1);
		play(&arena[indikasiLevel][0][0], panjangArena[indikasiLevel], lebarArena[indikasiLevel], database, &indikasiSelesai, &jumlahGerakan);
		if(indikasiSelesai == 1) {
			if(gerakanNormal[indikasiLevel] - jumlahGerakan > 0) bonus = gerakanNormal[indikasiLevel] - jumlahGerakan;
			*uang += indikasiLevel * 3 + bonus;
			if(indikasiLevel >= 20) printf("\nSelamat! Anda telah menyelesaikan level Spesial %d.\nJumlah gerakan: %d\nHatoken yang didapat: %d\n", indikasiLevel+1-20, jumlahGerakan, indikasiLevel * 3 + bonus);
			else printf("\nSelamat! Anda telah menyelesaikan level %d.\nJumlah gerakan: %d\nHatoken yang didapat: %d\n", indikasiLevel+1, jumlahGerakan, indikasiLevel * 3 + bonus);
			break;
		} else if(indikasiSelesai == 2) {
			if(indikasiLevel >= 20) printf("\nAnda keluar dari level Spesial %d.\n", indikasiLevel+1-20);
			else printf("\nAnda keluar dari level %d.\n", indikasiLevel+1);
			break;
		}
	}
}

void play(char *arr, int panjangArena, int lebarArena, char *database, int *indikasiSelesai, int *jumlahGerakan) {
	char input, arena[20][20], undo[1000][20][20];
	int goal=0, a=0, b=0, undoPlayer[1000][3];
	for(int x=0; x<lebarArena; x++) {
		for(int y=0; y<panjangArena; y++) {
			arena[x][y] = *(arr+(x*20)+y);
			if(arena[x][y] == '#') {
				arena[x][y] = database[0];
			} else if(arena[x][y] == '$') {
				arena[x][y] = database[1];
				goal++;
			} else if(arena[x][y] == 'X') {
				arena[x][y] = database[2];
			} else if(arena[x][y] == 'Y') {
				arena[x][y] = database[3];
			} else if(arena[x][y] == 'O') {
				arena[x][y] = database[4];
				a=x;
				b=y;
			} else if(arena[x][y] == '@') {
				arena[x][y] = database[5];
				a=x;
				b=y;
				goal++;
			} else if(arena[x][y] == ' ') {
				arena[x][y] = database[6]; 
			}
		}
	}
	while(goal>0) {
		for(int x=0; x<lebarArena; x++) {
			for(int y=0; y<panjangArena; y++) {
				printf("%c", arena[x][y]);
			}
            if(x == lebarArena-1) printf(" %d", *jumlahGerakan);
			printf("\n");
		}
        if(*jumlahGerakan == 999) {
            printf("\nAnda telah melebihi batas gerakan!");
            *indikasiSelesai = 2;
			return;
        }
		printf("\nMasukkan input: ");
		fflush(stdin);
		scanf(" %c", &input);
		if((input == 'w' || input == 'W') && arena[a-1][b] != database[0]) {
			if(arena[a][b] == database[4]) {
				if(arena[a-1][b] == database[6]) {
                    undoPlayer[*jumlahGerakan][0] = a;
                    undoPlayer[*jumlahGerakan][1] = b;
					undoPlayer[*jumlahGerakan][2] = goal;
                    for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
					swap(&arena[a][b], &arena[a-1][b]);
					a--;
					(*jumlahGerakan)++;
				} else if(arena[a-1][b] == database[1]) {
                    undoPlayer[*jumlahGerakan][0] = a;
                    undoPlayer[*jumlahGerakan][1] = b;
					undoPlayer[*jumlahGerakan][2] = goal;
                    for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
					arena[a-1][b] = database[6];
					arena[a][b] = database[5];
					swap(&arena[a][b], &arena[a-1][b]);
					a--;
					(*jumlahGerakan)++;
				} else if(arena[a-1][b] == database[2] && arena[a-2][b] != database[0] && arena[a-2][b] != database[2] && arena[a-2][b] != database[3]) {
					if(arena[a-2][b] == database[6]) {
                        undoPlayer[*jumlahGerakan][0] = a;
                        undoPlayer[*jumlahGerakan][1] = b;
						undoPlayer[*jumlahGerakan][2] = goal;
                        for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
						swap(&arena[a-1][b], &arena[a-2][b]);
						swap(&arena[a][b], &arena[a-1][b]);
						a--;
						(*jumlahGerakan)++;
					} else if(arena[a-2][b] == database[1]) {
                        undoPlayer[*jumlahGerakan][0] = a;
                        undoPlayer[*jumlahGerakan][1] = b;
						undoPlayer[*jumlahGerakan][2] = goal;
                        for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
						arena[a-2][b] = database[6];
						arena[a-1][b] = database[3];
						swap(&arena[a-1][b], &arena[a-2][b]);
						swap(&arena[a][b], &arena[a-1][b]);
						a--;
						goal--;
						(*jumlahGerakan)++;
					}
				} else if(arena[a-1][b] == database[3] && arena[a-2][b] != database[0] && arena[a-2][b] != database[2] && arena[a-2][b] != database[3]) {
					if(arena[a-2][b] == database[6]) {
                        undoPlayer[*jumlahGerakan][0] = a;
                        undoPlayer[*jumlahGerakan][1] = b;
						undoPlayer[*jumlahGerakan][2] = goal;
                        for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
						arena[a-1][b] = database[2];
						arena[a][b] = database[5];
						swap(&arena[a-1][b], &arena[a-2][b]);
						swap(&arena[a][b], &arena[a-1][b]);
						a--;
						goal++;
						(*jumlahGerakan)++;
					} else if(arena[a-2][b] == database[1]) {
                        undoPlayer[*jumlahGerakan][0] = a;
                        undoPlayer[*jumlahGerakan][1] = b;
						undoPlayer[*jumlahGerakan][2] = goal;
                        for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
						arena[a-2][b] = database[6];
						arena[a][b] = database[5];
						swap(&arena[a-1][b], &arena[a-2][b]);
						swap(&arena[a][b], &arena[a-1][b]);
						a--;
						(*jumlahGerakan)++;
					}
				} else printf("\a");
			} else if(arena[a][b] == database[5]) {
				if(arena[a-1][b] == database[6]) {
                    undoPlayer[*jumlahGerakan][0] = a;
                    undoPlayer[*jumlahGerakan][1] = b;
					undoPlayer[*jumlahGerakan][2] = goal;
                    for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
					arena[a-1][b] = database[1];
					arena[a][b] = database[4];
					swap(&arena[a][b], &arena[a-1][b]);
					a--;
					(*jumlahGerakan)++;
				} else if(arena[a-1][b] == database[1]) {
                    undoPlayer[*jumlahGerakan][0] = a;
                    undoPlayer[*jumlahGerakan][1] = b;
					undoPlayer[*jumlahGerakan][2] = goal;
                    for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
					swap(&arena[a][b], &arena[a-1][b]);
					a--;
					(*jumlahGerakan)++;
				} else if(arena[a-1][b] == database[2] && arena[a-2][b] != database[0] && arena[a-2][b] != database[2] && arena[a-2][b] != database[3]) {
					if(arena[a-2][b] == database[6]) {
                        undoPlayer[*jumlahGerakan][0] = a;
                        undoPlayer[*jumlahGerakan][1] = b;
						undoPlayer[*jumlahGerakan][2] = goal;
                        for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
						arena[a-2][b] = database[1];
						arena[a][b] = database[4];
						swap(&arena[a-1][b], &arena[a-2][b]);
						swap(&arena[a][b], &arena[a-1][b]);
						a--;
						(*jumlahGerakan)++;
					} else if(arena[a-2][b] == database[1]) {
                        undoPlayer[*jumlahGerakan][0] = a;
                        undoPlayer[*jumlahGerakan][1] = b;
						undoPlayer[*jumlahGerakan][2] = goal;
                        for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
						arena[a-1][b] = database[3];
						arena[a][b] = database[4];
						swap(&arena[a-1][b], &arena[a-2][b]);
						swap(&arena[a][b], &arena[a-1][b]);
						a--;
						goal--;
						(*jumlahGerakan)++;
					}
				} else if(arena[a-1][b] == database[3] && arena[a-2][b] != database[0] && arena[a-2][b] != database[2] && arena[a-2][b] != database[3]) {
					if(arena[a-2][b] == database[6]) {
                        undoPlayer[*jumlahGerakan][0] = a;
                        undoPlayer[*jumlahGerakan][1] = b;
						undoPlayer[*jumlahGerakan][2] = goal;
                        for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
						arena[a-2][b] = database[1];
						arena[a-1][b] = database[2];
						swap(&arena[a-1][b], &arena[a-2][b]);
						swap(&arena[a][b], &arena[a-1][b]);
						a--;
						goal++;
						(*jumlahGerakan)++;
					} else if(arena[a-2][b] == database[1]) {
                        undoPlayer[*jumlahGerakan][0] = a;
                        undoPlayer[*jumlahGerakan][1] = b;
						undoPlayer[*jumlahGerakan][2] = goal;
                        for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
						swap(&arena[a-1][b], &arena[a-2][b]);
						swap(&arena[a][b], &arena[a-1][b]);
						a--;
						(*jumlahGerakan)++;
					}
				} else printf("\a");
			}
		} else if((input == 'a' ||input == 'A') && arena[a][b-1] != database[0]) {
			if(arena[a][b] == database[4]) {
				if(arena[a][b-1] == database[6]) {
                    undoPlayer[*jumlahGerakan][0] = a;
                    undoPlayer[*jumlahGerakan][1] = b;
					undoPlayer[*jumlahGerakan][2] = goal;
                    for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
					swap(&arena[a][b], &arena[a][b-1]);
					b--;
					(*jumlahGerakan)++;
				} else if(arena[a][b-1] == database[1]) {
                    undoPlayer[*jumlahGerakan][0] = a;
                    undoPlayer[*jumlahGerakan][1] = b;
					undoPlayer[*jumlahGerakan][2] = goal;
                    for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
					arena[a][b-1] = database[6];
					arena[a][b] = database[5];
					swap(&arena[a][b], &arena[a][b-1]);
					b--;
					(*jumlahGerakan)++;
				} else if(arena[a][b-1] == database[2] && arena[a][b-2] != database[0] && arena[a][b-2] != database[2] && arena[a][b-2] != database[3]) {
					if(arena[a][b-2] == database[6]) {
                        undoPlayer[*jumlahGerakan][0] = a;
                        undoPlayer[*jumlahGerakan][1] = b;
						undoPlayer[*jumlahGerakan][2] = goal;
                        for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
						swap(&arena[a][b-1], &arena[a][b-2]);
						swap(&arena[a][b], &arena[a][b-1]);
						b--;
						(*jumlahGerakan)++;
					} else if(arena[a][b-2] == database[1]) {
                        undoPlayer[*jumlahGerakan][0] = a;
                        undoPlayer[*jumlahGerakan][1] = b;
						undoPlayer[*jumlahGerakan][2] = goal;
                        for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
						arena[a][b-2] = database[6];
						arena[a][b-1] = database[3];
						swap(&arena[a][b-1], &arena[a][b-2]);
						swap(&arena[a][b], &arena[a][b-1]);
						b--;
						goal--;
						(*jumlahGerakan)++;
					}
				} else if(arena[a][b-1] == database[3] && arena[a][b-2] != database[0] && arena[a][b-2] != database[2] && arena[a][b-2] != database[3]) {
					if(arena[a][b-2] == database[6]) {
                        undoPlayer[*jumlahGerakan][0] = a;
                        undoPlayer[*jumlahGerakan][1] = b;
						undoPlayer[*jumlahGerakan][2] = goal;
                        for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
						arena[a][b-1] = database[2];
						arena[a][b] = database[5];
						swap(&arena[a][b-1], &arena[a][b-2]);
						swap(&arena[a][b], &arena[a][b-1]);
						b--;
						goal++;
						(*jumlahGerakan)++;
					} else if(arena[a][b-2] == database[1]) {
                        undoPlayer[*jumlahGerakan][0] = a;
                        undoPlayer[*jumlahGerakan][1] = b;
						undoPlayer[*jumlahGerakan][2] = goal;
                        for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
						arena[a][b-2] = database[6];
						arena[a][b] = database[5];
						swap(&arena[a][b-1], &arena[a][b-2]);
						swap(&arena[a][b], &arena[a][b-1]);
						b--;
						(*jumlahGerakan)++;
					}
				} else printf("\a");
			} else if(arena[a][b] == database[5]) {
				if(arena[a][b-1] == database[6]) {
                    undoPlayer[*jumlahGerakan][0] = a;
                    undoPlayer[*jumlahGerakan][1] = b;
					undoPlayer[*jumlahGerakan][2] = goal;
                    for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
					arena[a][b-1] = database[1];
					arena[a][b] = database[4];
					swap(&arena[a][b], &arena[a][b-1]);
					b--;
					(*jumlahGerakan)++;
				} else if(arena[a][b-1] == database[1]) {
                    undoPlayer[*jumlahGerakan][0] = a;
                    undoPlayer[*jumlahGerakan][1] = b;
					undoPlayer[*jumlahGerakan][2] = goal;
                    for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
					swap(&arena[a][b], &arena[a][b-1]);
					b--;
					(*jumlahGerakan)++;
				} else if(arena[a][b-1] == database[2] && arena[a][b-2] != database[0] && arena[a][b-2] != database[2] && arena[a][b-2] != database[3]) {
					if(arena[a][b-2] == database[6]) {
                        undoPlayer[*jumlahGerakan][0] = a;
                        undoPlayer[*jumlahGerakan][1] = b;
						undoPlayer[*jumlahGerakan][2] = goal;
                        for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
						arena[a][b-2] = database[1];
						arena[a][b] = database[4];
						swap(&arena[a][b-1], &arena[a][b-2]);
						swap(&arena[a][b], &arena[a][b-1]);
						b--;
						(*jumlahGerakan)++;
					} else if(arena[a][b-2] == database[1]) {
                        undoPlayer[*jumlahGerakan][0] = a;
                        undoPlayer[*jumlahGerakan][1] = b;
						undoPlayer[*jumlahGerakan][2] = goal;
                        for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
						arena[a][b-1] = database[3];
						arena[a][b] = database[4];
						swap(&arena[a][b-1], &arena[a][b-2]);
						swap(&arena[a][b], &arena[a][b-1]);
						b--;
						goal--;
						(*jumlahGerakan)++;
					}
				} else if(arena[a][b-1] == database[3] && arena[a][b-2] != database[0] && arena[a][b-2] != database[2] && arena[a][b-2] != database[3]) {
					if(arena[a][b-2] == database[6]) {
                        undoPlayer[*jumlahGerakan][0] = a;
                        undoPlayer[*jumlahGerakan][1] = b;
						undoPlayer[*jumlahGerakan][2] = goal;
                        for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
						arena[a][b-2] = database[1];
						arena[a][b-1] = database[2];
						swap(&arena[a][b-1], &arena[a][b-2]);
						swap(&arena[a][b], &arena[a][b-1]);
						b--;
						goal++;
						(*jumlahGerakan)++;
					} else if(arena[a][b-2] == database[1]) {
                        undoPlayer[*jumlahGerakan][0] = a;
                        undoPlayer[*jumlahGerakan][1] = b;
						undoPlayer[*jumlahGerakan][2] = goal;
                        for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
						swap(&arena[a][b-1], &arena[a][b-2]);
						swap(&arena[a][b], &arena[a][b-1]);
						b--;
						(*jumlahGerakan)++;
					}
				} else printf("\a");
			}
		} else if((input == 's' ||input == 'S') && arena[a+1][b] != database[0]) {
			if(arena[a][b] == database[4]) {
				if(arena[a+1][b] == database[6]) {
                    undoPlayer[*jumlahGerakan][0] = a;
                    undoPlayer[*jumlahGerakan][1] = b;
					undoPlayer[*jumlahGerakan][2] = goal;
                    for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
					swap(&arena[a][b], &arena[a+1][b]);
					a++;
					(*jumlahGerakan)++;
				} else if(arena[a+1][b] == database[1]) {
                    undoPlayer[*jumlahGerakan][0] = a;
                    undoPlayer[*jumlahGerakan][1] = b;
					undoPlayer[*jumlahGerakan][2] = goal;
                    for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
					arena[a+1][b] = database[6];
					arena[a][b] = database[5];
					swap(&arena[a][b], &arena[a+1][b]);
					a++;
					(*jumlahGerakan)++;
				} else if(arena[a+1][b] == database[2] && arena[a+2][b] != database[0] && arena[a+2][b] != database[2] && arena[a+2][b] != database[3]) {
					if(arena[a+2][b] == database[6]) {
                        undoPlayer[*jumlahGerakan][0] = a;
                        undoPlayer[*jumlahGerakan][1] = b;
						undoPlayer[*jumlahGerakan][2] = goal;
                        for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
						swap(&arena[a+1][b], &arena[a+2][b]);
						swap(&arena[a][b], &arena[a+1][b]);
						a++;
						(*jumlahGerakan)++;
					} else if(arena[a+2][b] == database[1]) {
                        undoPlayer[*jumlahGerakan][0] = a;
                        undoPlayer[*jumlahGerakan][1] = b;
						undoPlayer[*jumlahGerakan][2] = goal;
                        for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
						arena[a+2][b] = database[6];
						arena[a+1][b] = database[3];
						swap(&arena[a+1][b], &arena[a+2][b]);
						swap(&arena[a][b], &arena[a+1][b]);
						a++;
						goal--;
						(*jumlahGerakan)++;
					}
				} else if(arena[a+1][b] == database[3] && arena[a+2][b] != database[0] && arena[a+2][b] != database[2] && arena[a+2][b] != database[3]) {
					if(arena[a+2][b] == database[6]) {
                        undoPlayer[*jumlahGerakan][0] = a;
                        undoPlayer[*jumlahGerakan][1] = b;
						undoPlayer[*jumlahGerakan][2] = goal;
                        for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
						arena[a+1][b] = database[2];
						arena[a][b] = database[5];
						swap(&arena[a+1][b], &arena[a+2][b]);
						swap(&arena[a][b], &arena[a+1][b]);
						a++;
						goal++;
						(*jumlahGerakan)++;
					} else if(arena[a+2][b] == database[1]) {
                        undoPlayer[*jumlahGerakan][0] = a;
                        undoPlayer[*jumlahGerakan][1] = b;
						undoPlayer[*jumlahGerakan][2] = goal;
                        for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
						arena[a+2][b] = database[6];
						arena[a][b] = database[5];
						swap(&arena[a+1][b], &arena[a+2][b]);
						swap(&arena[a][b], &arena[a+1][b]);
						a++;
						(*jumlahGerakan)++;
					}
				} else printf("\a");
			} else if(arena[a][b] == database[5]) {
				if(arena[a+1][b] == database[6]) {
                    undoPlayer[*jumlahGerakan][0] = a;
                    undoPlayer[*jumlahGerakan][1] = b;
					undoPlayer[*jumlahGerakan][2] = goal;
                    for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
					arena[a+1][b] = database[1];
					arena[a][b] = database[4];
					swap(&arena[a][b], &arena[a+1][b]);
					a++;
					(*jumlahGerakan)++;
				} else if(arena[a+1][b] == database[1]) {
                    undoPlayer[*jumlahGerakan][0] = a;
                    undoPlayer[*jumlahGerakan][1] = b;
					undoPlayer[*jumlahGerakan][2] = goal;
                    for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
					swap(&arena[a][b], &arena[a+1][b]);
					a++;
					(*jumlahGerakan)++;
				} else if(arena[a+1][b] == database[2] && arena[a+2][b] != database[0] && arena[a+2][b] != database[2] && arena[a+2][b] != database[3]) {
					if(arena[a+2][b] == database[6]) {
                        undoPlayer[*jumlahGerakan][0] = a;
                        undoPlayer[*jumlahGerakan][1] = b;
						undoPlayer[*jumlahGerakan][2] = goal;
                        for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
						arena[a+2][b] = database[1];
						arena[a][b] = database[4];
						swap(&arena[a+1][b], &arena[a+2][b]);
						swap(&arena[a][b], &arena[a+1][b]);
						a++;
						(*jumlahGerakan)++;
					} else if(arena[a+2][b] == database[1]) {
                        undoPlayer[*jumlahGerakan][0] = a;
                        undoPlayer[*jumlahGerakan][1] = b;
						undoPlayer[*jumlahGerakan][2] = goal;
                        for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
						arena[a+1][b] = database[3];
						arena[a][b] = database[4];
						swap(&arena[a+1][b], &arena[a+2][b]);
						swap(&arena[a][b], &arena[a+1][b]);
						a++;
						goal--;
						(*jumlahGerakan)++;
					}
				} else if(arena[a+1][b] == database[3] && arena[a+2][b] != database[0] && arena[a+2][b] != database[2] && arena[a+2][b] != database[3]) {
					if(arena[a+2][b] == database[6]) {
                        undoPlayer[*jumlahGerakan][0] = a;
                        undoPlayer[*jumlahGerakan][1] = b;
						undoPlayer[*jumlahGerakan][2] = goal;
                        for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
						arena[a+2][b] = database[1];
						arena[a+1][b] = database[2];
						swap(&arena[a+1][b], &arena[a+2][b]);
						swap(&arena[a][b], &arena[a+1][b]);
						a++;
						goal++;
						(*jumlahGerakan)++;
					} else if(arena[a+2][b] == database[1]) {
                        undoPlayer[*jumlahGerakan][0] = a;
                        undoPlayer[*jumlahGerakan][1] = b;
						undoPlayer[*jumlahGerakan][2] = goal;
                        for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
						swap(&arena[a+1][b], &arena[a+2][b]);
						swap(&arena[a][b], &arena[a+1][b]);
						a++;
						(*jumlahGerakan)++;
					}
				} else printf("\a");
			}
		} else if((input == 'd' ||input == 'D') && arena[a][b+1] != database[0]) {
			if(arena[a][b] == database[4]) {
				if(arena[a][b+1] == database[6]) {
                    undoPlayer[*jumlahGerakan][0] = a;
                    undoPlayer[*jumlahGerakan][1] = b;
					undoPlayer[*jumlahGerakan][2] = goal;
                    for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
					swap(&arena[a][b], &arena[a][b+1]);
					b++;
					(*jumlahGerakan)++;
				} else if(arena[a][b+1] == database[1]) {
                    undoPlayer[*jumlahGerakan][0] = a;
                    undoPlayer[*jumlahGerakan][1] = b;
					undoPlayer[*jumlahGerakan][2] = goal;
                    for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
					arena[a][b+1] = database[6];
					arena[a][b] = database[5];
					swap(&arena[a][b], &arena[a][b+1]);
					b++;
					(*jumlahGerakan)++;
				} else if(arena[a][b+1] == database[2] && arena[a][b+2] != database[0] && arena[a][b+2] != database[2] && arena[a][b+2] != database[3]) {
					if(arena[a][b+2] == database[6]) {
                        undoPlayer[*jumlahGerakan][0] = a;
                        undoPlayer[*jumlahGerakan][1] = b;
						undoPlayer[*jumlahGerakan][2] = goal;
                        for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
						swap(&arena[a][b+1], &arena[a][b+2]);
						swap(&arena[a][b], &arena[a][b+1]);
						b++;
						(*jumlahGerakan)++;
					} else if(arena[a][b+2] == database[1]) {
                        undoPlayer[*jumlahGerakan][0] = a;
                        undoPlayer[*jumlahGerakan][1] = b;
						undoPlayer[*jumlahGerakan][2] = goal;
                        for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
						arena[a][b+2] = database[6];
						arena[a][b+1] = database[3];
						swap(&arena[a][b+1], &arena[a][b+2]);
						swap(&arena[a][b], &arena[a][b+1]);
						b++;
						goal--;
						(*jumlahGerakan)++;
					}
				} else if(arena[a][b+1] == database[3] && arena[a][b+2] != database[0] && arena[a][b+2] != database[2] && arena[a][b+2] != database[3]) {
					if(arena[a][b+2] == database[6]) {
                        undoPlayer[*jumlahGerakan][0] = a;
                        undoPlayer[*jumlahGerakan][1] = b;
						undoPlayer[*jumlahGerakan][2] = goal;
                        for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
						arena[a][b+1] = database[2];
						arena[a][b] = database[5];
						swap(&arena[a][b+1], &arena[a][b+2]);
						swap(&arena[a][b], &arena[a][b+1]);
						b++;
						goal++;
						(*jumlahGerakan)++;
					} else if(arena[a][b+2] == database[1]) {
                        undoPlayer[*jumlahGerakan][0] = a;
                        undoPlayer[*jumlahGerakan][1] = b;
						undoPlayer[*jumlahGerakan][2] = goal;
                        for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
						arena[a][b+2] = database[6];
						arena[a][b] = database[5];
						swap(&arena[a][b+1], &arena[a][b+2]);
						swap(&arena[a][b], &arena[a][b+1]);
						b++;
						(*jumlahGerakan)++;
					}
				} else printf("\a");
			} else if(arena[a][b] == database[5]) {
				if(arena[a][b+1] == database[6]) {
                    undoPlayer[*jumlahGerakan][0] = a;
                    undoPlayer[*jumlahGerakan][1] = b;
					undoPlayer[*jumlahGerakan][2] = goal;
                    for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
					arena[a][b+1] = database[1];
					arena[a][b] = database[4];
					swap(&arena[a][b], &arena[a][b+1]);
					b++;
					(*jumlahGerakan)++;
				} else if(arena[a][b+1] == database[1]) {
                    undoPlayer[*jumlahGerakan][0] = a;
                    undoPlayer[*jumlahGerakan][1] = b;
					undoPlayer[*jumlahGerakan][2] = goal;
                    for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
					swap(&arena[a][b], &arena[a][b+1]);
					b++;
					(*jumlahGerakan)++;
				} else if(arena[a][b+1] == database[2] && arena[a][b+2] != database[0] && arena[a][b+2] != database[2] && arena[a][b+2] != database[3]) {
					if(arena[a][b+2] == database[6]) {
                        undoPlayer[*jumlahGerakan][0] = a;
                        undoPlayer[*jumlahGerakan][1] = b;
						undoPlayer[*jumlahGerakan][2] = goal;
                        for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
						arena[a][b+2] = database[1];
						arena[a][b] = database[4];
						swap(&arena[a][b+1], &arena[a][b+2]);
						swap(&arena[a][b], &arena[a][b+1]);
						b++;
						(*jumlahGerakan)++;
					} else if(arena[a][b+2] == database[1]) {
                        undoPlayer[*jumlahGerakan][0] = a;
                        undoPlayer[*jumlahGerakan][1] = b;
						undoPlayer[*jumlahGerakan][2] = goal;
                        for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
						arena[a][b+1] = database[3];
						arena[a][b] = database[4];
						swap(&arena[a][b+1], &arena[a][b+2]);
						swap(&arena[a][b], &arena[a][b+1]);
						b++;
						goal--;
						(*jumlahGerakan)++;
					}
				} else if(arena[a][b+1] == database[3] && arena[a][b+2] != database[0] && arena[a][b+2] != database[2] && arena[a][b+2] != database[3]) {
					if(arena[a][b+2] == database[6]) {
                        undoPlayer[*jumlahGerakan][0] = a;
                        undoPlayer[*jumlahGerakan][1] = b;
						undoPlayer[*jumlahGerakan][2] = goal;
                        for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
						arena[a][b+2] = database[1];
						arena[a][b+1] = database[2];
						swap(&arena[a][b+1], &arena[a][b+2]);
						swap(&arena[a][b], &arena[a][b+1]);
						b++;
						goal++;
						(*jumlahGerakan)++;
					} else if(arena[a][b+2] == database[1]) {
                        undoPlayer[*jumlahGerakan][0] = a;
                        undoPlayer[*jumlahGerakan][1] = b;
						undoPlayer[*jumlahGerakan][2] = goal;
                        for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) undo[*jumlahGerakan][x][y] = arena[x][y];
						swap(&arena[a][b+1], &arena[a][b+2]);
						swap(&arena[a][b], &arena[a][b+1]);
						b++;
						(*jumlahGerakan)++;
					}
				} else printf("\a");
			}
		} else if(input == 'r' || input == 'R') {
			printf("\nRESTART");
			return;
		} else if(input == 'x' || input == 'X') {
			*indikasiSelesai = 2;
			return;
		} else if((input == 'z' || input == 'Z') && *jumlahGerakan > 0) {
            (*jumlahGerakan)--;
            a = undoPlayer[*jumlahGerakan][0];
            b = undoPlayer[*jumlahGerakan][1];
			goal = undoPlayer[*jumlahGerakan][2];
            for(int x=0; x<lebarArena; x++) for(int y=0; y<panjangArena; y++) arena[x][y] = undo[*jumlahGerakan][x][y];
        } else printf("\a");
	}
	for(int x=0; x<lebarArena; x++) {
		for(int y=0; y<panjangArena; y++) {
			printf("%c", arena[x][y]);
		}
        if(x == lebarArena-1) printf(" %d", *jumlahGerakan);
		printf("\n");
	}
	*indikasiSelesai = 1;
}

void swap(char *a, char *b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}