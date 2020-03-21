
Salim Bin Usman - 05111840000104

Ryan Chandra Sasmita -05111840000136

Kelompok E01

## Soal 1
Buatlah program C yang menyerupai crontab untuk menjalankan script bash dengan
ketentuan sebagai berikut:

a. Program menerima 4 argumen berupa:

i. Detik: 0-59 atau * (any value)

ii. Menit: 0-59 atau * (any value)

iii. Jam: 0-23 atau * (any value)

iv. Path file .sh

b. Program akan mengeluarkan pesan error jika argumen yang diberikan tidak sesuai

c. Program hanya menerima 1 config cron

d. Program berjalan di background (daemon)

e. Tidak boleh menggunakan fungsi system()

Contoh: ./program \* 34 7 /home/somi/test.sh

Program dengan argumen seperti contoh di atas akan menjalankan script test.sh setiap detik pada jam 07:34.

### Jawaban :

#### Bagian 1
```
    if(argc<5){
        printf("Argumen Kurang\n");
        return 0;
    }

    if((atoi(argv[1])>=0 &&atoi(argv[1])<60) || strcmp(argv[1],"*")==0){
        puts(argv[1]);
    }
    else{
        puts("EROR ARGUMEN 1 BRO");
        return 0;
    }

    if((atoi(argv[2])>=0 &&atoi(argv[2])<60) || strcmp(argv[2],"*")==0){
        puts(argv[2]);
    }
    else{
        puts("EROR ARGUMEN 2 BRO");
        return 0;
    }

    if((atoi(argv[3])>=0 &&atoi(argv[3])<60) || strcmp(argv[3],"*")==0){
        puts(argv[3]);
    }
    else{
        puts("EROR ARGUMEN 3 BRO");
        return 0;
    }
    // puts(argv[4]);
    if(access(argv[4],F_OK)==-1){
        puts("FILENYA GAADA!!\n");
        return 0;
    }
```

#### Bagian 2 
```
    pid_t pid, sid;        // Variabel untuk menyimpan PID

    pid = fork();     // Menyimpan PID dari Child Process

    /* Keluar saat fork gagal
    * (nilai variabel pid < 0) */
    if (pid < 0) {
        exit(EXIT_FAILURE);
    }

    /* Keluar saat fork berhasil
    * (nilai variabel pid adalah PID dari child process) */
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

    umask(0);

    sid = setsid();
    if (sid < 0) {
        exit(EXIT_FAILURE);
    }

    if ((chdir("/home/salim/modul2")) < 0) {
        exit(EXIT_FAILURE);
    }

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
```

#### Bagian 3
```
    time_t rawtime=time(NULL);
    struct tm *timeinfo=localtime(&rawtime);
    int sec=timeinfo->tm_sec;
    int min=timeinfo->tm_min;
    int hour=timeinfo->tm_hour;

    if(sec==atoi(argv[1])||strcmp(argv[1],"*")==0){
        sec=100;
    }
    if(min==atoi(argv[2])||strcmp(argv[2],"*")==0){
        min=100;
    }
    if(hour==atoi(argv[3])||strcmp(argv[3],"*")==0){
        hour=100;
    }
    if(sec==100&&min==100&&hour==100){
        if(fork()==0){
            char *args[] = {"bash",argv[4],NULL};
            execv("/bin/bash",args);
        }   
    }
    sleep(1);
```

### Penjelasan :

Bagian 1 -> Bagian ini digunakan untuk memvalidasi argumen yang diberikan apabila ada ketidak sesuaian akan mengeluarkan pesan error dan program berhenti

Bagian 2 -> Bagian ini digunakan untuk menjadikan program yang kita jalankan menjadi daemon/berjalan pada latar belakang

Bagian 3 -> Bagian ini digunakan untuk menjalankan konfigurasi cron yang diberikan oleh input, menggunakan perbandingan string apabila inputan berupa * dan membandingkan nilai waktu sekarang dengan inputan argumen, jika hasil perbandingan semua bernilai benar maka jalankan file bash pada argumen terakhir

## Soal 2
Shisoppu mantappu! itulah yang selalu dikatakan Kiwa setiap hari karena sekarang dia merasa sudah jago materi sisop. Karena merasa jago, suatu hari Kiwa iseng membuat sebuah program.

a. Pertama-tama, Kiwa membuat sebuah folder khusus, di dalamnya dia membuat sebuah program C yang per 30 detik membuat sebuah folder dengan nama timestamp [YYYY-mm-dd_HH:ii:ss].

b. Tiap-tiap folder lalu diisi dengan 20 gambar yang di download darihttps://picsum.photos/, dimana tiap gambar di download setiap 5 detik. Tiap gambar berbentuk persegi dengan ukuran (t%1000)+100 piksel dimana t adalah detik Epoch Unix. Gambar tersebut diberi nama dengan format timestamp [YYYY-mm-dd_HH:ii:ss].

c. Agar rapi, setelah sebuah folder telah terisi oleh 20 gambar, folder akan di zip danfolder akan di delete(sehingga hanya menyisakan .zip).

d. Karena takut program tersebut lepas kendali, Kiwa ingin program tersebut men- generate sebuah program "killer" yang siap di run(executable) untuk menterminasi semua operasi program tersebut. Setelah di run, program yang menterminasi ini lalu akan mendelete dirinya sendiri.

e. Kiwa menambahkan bahwa program utama bisa dirun dalam dua mode, yaitu MODE_A dan MODE_B. untuk mengaktifkan MODE_A, program harus dijalankan dengan argumen -a. Untuk MODE_B, program harus dijalankan dengan argumen -b. Ketika dijalankan dalam MODE_A, program utama akan langsung menghentikan semua operasinya ketika program killer dijalankan. Untuk MODE_B, ketika program killer dijalankan, program utama akan berhenti tapi membiarkan proses di setiap folder yang masih berjalan sampai selesai(semua folder terisi gambar, terzip lalu di delete).

Kiwa lalu terbangun dan sedih karena menyadari programnya hanya sebuah mimpi.
 Buatlah program dalam mimpi Kiwa jadi nyata!

Catatan:

- Tidak boleh memakai system().

- Program utama harus ter-detach dari terminal

Hint:

- Gunakan fitur picsum.photos untuk mendapatkan gambar dengan ukuran tertentu

- Epoch Unix bisa didapatkan dari time()

### Jawaban :
### Penjelasan :

## Soal 3
Jaya adalah seorang programmer handal mahasiswa informatika. Suatu hari dia memperoleh tugas yang banyak dan berbeda tetapi harus dikerjakan secara bersamaan (multiprocessing).

a. Program buatan jaya harus bisa membuat dua direktori di “/home/[USER]/modul2/”. Direktori yang pertama diberi nama “indomie”, lalu lima detik kemudian membuat direktori yang kedua bernama “sedaap”.

b. Kemudian program tersebut harus meng-ekstrak file jpg.zip di direktori “/home/[USER]/modul2/”. Setelah tugas sebelumnya selesai, ternyata tidak hanya itu tugasnya.

c. Diberilah tugas baru yaitu setelah di ekstrak, hasil dari ekstrakan tersebut (di dalam direktori “home/[USER]/modul2/jpg/”) harus dipindahkan sesuai dengan pengelompokan, semua file harus dipindahkan ke “/home/[USER]/modul2/sedaap/” dan semua direktori harus dipindahkan ke “/home/[USER]/modul2/indomie/”.

d. Untuk setiap direktori yang dipindahkan ke “/home/[USER]/modul2/indomie/” harus membuat dua file kosong. File yang pertama diberi nama “coba1.txt”, lalu 3 detik kemudian membuat file bernama “coba2.txt”. (contoh “/home/[USER]/modul2/indomie/{nama_folder}/coba1.txt”). 

Karena Jaya terlalu banyak tugas dia jadi stress, jadi bantulah Jaya agar bisa membuat program tersebut.

Catatan :

- Tidak boleh memakai system().

- Tidak boleh memakai function C mkdir() ataupun rename().

- Gunakan exec dan fork

- Direktori “.” dan “..” tidak termasuk

### Jawaban

#### Bagian 1
```
    if(fork()==0){
        char *args[]= {"copy","-r","/home/salim/newfolder","/home/salim/modul2",NULL};
        execv("/bin/cp",args);
    }
    while((wait(&status))>0);

    if(fork()==0){
            char *args[]= {"rename","newfolder","indomie",NULL};
            execv("/bin/mv",args);
    }
    while((wait(&status))>0);

    sleep(5);
    if(fork()==0){
        char *args[]= {"copy","-r","/home/salim/newfolder","/home/salim/modul2",NULL};
        execv("/bin/cp",args);
    }
    while((wait(&status))>0);

    if(fork()==0){
        char *args[]= {"rename","newfolder","sedaap",NULL};
        execv("/bin/mv",args);        
    }
    while((wait(&status))>0);
```

#### Bagian 2
```
    if(fork()==0){
        char *args[]= {"unzip","jpg.zip",NULL};
        execv("/usr/bin/unzip",args);
    }
    while((wait(&status))>0);
```

#### Bagian 3 
```
    struct dirent *drnt;
    DIR *dir = opendir("/home/salim/modul2/jpg");
    if(dir){
            while(drnt = readdir(dir))
            {
                -- BAGIAN 4 --
            }
            closedir(dir);
    }
```

#### Bagian 4
```
    struct stat sb;

    char args2[50]="/home/salim/modul2/jpg/";
    strcat(args2,drnt->d_name);

    if(stat(args2, &sb)==0 &&S_ISDIR(sb.st_mode)){
        --- BAGIAN 5 a ---
    }
    else{
        --- BAGIAN 5 b ---
    }
```

#### Bagian 5 a
```
    if(fork()==0){
        char *args[]= {"move",args2,"/home/salim/modul2/indomie",NULL};
        execv("/bin/mv",args);
    }
    while((wait(&status))>0);
    char args3[50];
    strcpy(args3,"/home/salim/modul2/indomie/");
    strcat(args3,drnt->d_name);
    strcat(args3,"/coba1.txt");
    if(fork()==0){
        char *args[]= {"touch",args3,NULL};
        execv("/bin/touch",args);
    }
    while((wait(&status))>0);

    strcpy(args3,"/home/salim/modul2/indomie/");
    strcat(args3,drnt->d_name);
    strcat(args3,"/coba2.txt");
    sleep(3);
    if(fork()==0){
        char *args[]= {"touch",args3,NULL};
        execv("/bin/touch",args);
    }
    while((wait(&status))>0);
```

#### Bagian 5 b
```
    if(fork()==0){
        char *args[]= {"move",args2,"/home/salim/modul2/sedaap",NULL};
        execv("/bin/mv",args);
    }
    while((wait(&status))>0);
```
### Penjelasan

Bagian 1 -> Bagian ini membuat 2 folder pada path /home/(u_name)/modul2 yaitu indomie dan sedaap

Bagian 2 -> Bagian ini mengunzip file jpg.zip

Bagian 3 -> Bagian ini melakukan iterasi didalam directory jpg yang sebelumnya telah di ekstrak

Bagian 4 -> Bagian ini melakukan pengecekan apakah iterasi yang sedang dilakukan merupakan file atau directory

Bagian 5 a -> Bagian ini dieksekusi ketika iterasi yang dilakukan merupakan directory, yaitu memindahkannya ke indomie serta membuat 2 file (coba1.txt,coba2.txt) didalam directory tersebut dengan sela 3 detik

Bagian 5 b -> Bagian ini dieksekusi ketika itereasi yang dilakukan merupakan file, yaitu memindahkannya ke sedaap
