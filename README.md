# 🔗 Pipex

École 42 projesi olan **Pipex**, Unix shell'deki pipe (`|`) işlevselliğini C dilinde yeniden implemente eden bir programdır. Bu proje, process yönetimi, pipe kullanımı ve file descriptor manipülasyonu konularında derinlemesine bilgi kazandırmayı amaçlar.

## 📝 Proje Açıklaması

Pipex programı, shell'deki aşağıdaki komut yapısını taklit eder:
```bash
< file1 cmd1 | cmd2 > file2
```

Bu komut, `file1`'i okur, `cmd1`'e input olarak verir, `cmd1`'in çıktısını `cmd2`'ye pipe eder ve son olarak `cmd2`'nin çıktısını `file2`'ye yazar.

### Özellikler

- ✅ **Pipe İşlemleri**: Birden fazla komut arasında veri aktarımı
- ✅ **File I/O**: Input ve output dosya işlemleri
- ✅ **Process Yönetimi**: Fork, exec ve wait system call'ları
- ✅ **Error Handling**: Kapsamlı hata yönetimi
- ✅ **Here Document**: Shell'deki `<<` işlevselliği
- ✅ **Memory Management**: Bellek sızıntısı olmadan çalışma

## 🛠️ Kurulum

### Derleme
```bash
make
```

### Temizleme
```bash
make clean  # Object dosyalarını siler
make fclean # Tüm derleme çıktılarını siler
make re     # Temizleyip tekrar derler
```

## 🚀 Kullanım

### Temel Kullanım
```bash
./pipex infile "cmd1" "cmd2" outfile
```

**Örnek:**
```bash
./pipex input.txt "cat" "wc -l" output.txt
# Eşdeğer shell komutu: < input.txt cat | wc -l > output.txt
```

### Here Document
```bash
./pipex here_doc LIMITER "cmd1" "cmd2" outfile
```

**Örnek:**
```bash
./pipex here_doc EOF "tr a-z A-Z" "grep HELLO" output.txt
# Girdi EOF görene kadar alınır ve komutlara pipe edilir
```

### Çoklu Pipe
```bash
./pipex input.txt "cmd1" "cmd2" "cmd3" output.txt
# 3 veya daha fazla komut zincirleme yapılabilir
```

## 📁 Proje Yapısı

```
pipex/
├── main.c              # Ana program dosyası
├── Makefile            # Derleme kuralları
├── src/                # Kaynak kod dosyaları
│   ├── pipex.h         # Header dosyası
│   ├── cmd.c           # Komut işleme fonksiyonları
│   ├── exec.c          # Program yürütme fonksiyonları
│   ├── heredot.c       # Here document implementasyonu
│   ├── init_vars.c     # Değişken başlatma
│   ├── path.c          # PATH çözümleme
│   ├── pipe.c          # Pipe işlemleri
│   └── utils.c         # Yardımcı fonksiyonlar
├── libft/              # Kişisel C kütüphanesi
├── ft_printf/          # Printf implementasyonu
└── get_next_line/      # Satır okuma fonksiyonu
```

## 🔧 Teknik Detaylar

### Kullanılan System Call'lar
- `fork()` - Yeni process oluşturma
- `pipe()` - Pipe oluşturma
- `dup2()` - File descriptor yönlendirme
- `execve()` - Program çalıştırma
- `waitpid()` - Child process'leri bekleme
- `open()`, `close()`, `read()`, `write()` - File I/O

### Hata Yönetimi
Program aşağıdaki durumlarda uygun hata mesajları verir:
- Dosya bulunamadığında
- Komut bulunamadığında
- İzin hatalarında
- Pipe oluşturma hatalarında
- Memory allocation hatalarında

## 📋 École 42 Gereksinimleri

- ✅ Norm kurallarına uygunluk
- ✅ Makefile zorunlu kuralları (NAME, all, clean, fclean, re)
- ✅ Memory leak kontrolü (Valgrind ile test edilmiş)
- ✅ Segmentation fault koruması
- ✅ libft kullanımı
- ✅ Bonus kısım implementasyonu (here_doc, çoklu pipe)

---

*42 İstanbul - Pipex Projesi | 2025*
