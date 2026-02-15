*This project has been created as part of the 42 curriculum by mucelep.*

# LIBFT

---

## 🌐 ENGLISH VERSION

## Description

Libft is the first personal C library project at 42. The goal is to **reimplement a selection of standard C library functions** and create additional useful functions, including **linked list operations**.

This project helps build a solid foundation in **memory management, pointers, and low-level string handling**, while encouraging modular and reusable code design.

---

## 🎯 Objectives

- Deepen understanding of **malloc, free, and pointer manipulation**
- Learn **string and memory handling** at a low level
- Write **reusable, well-structured C functions**
- Understand how standard functions work internally without using existing libc implementations

---

## 📚 Library Scope

The library covers:
- **Character type checks** (isalpha, isdigit, etc.)
- **String manipulation** (strlen, strlcpy, strlcat, etc.)
- **Memory operations** (memset, memcpy, memmove, bzero)
- **Data conversion** (atoi, itoa)
- **Output to file descriptors** (putchar_fd, putstr_fd, putendl_fd, putnbr_fd)
- **Linked list operations** (ft_lstnew, ft_lstadd_front/back, ft_lstdelone, ft_lstclear, ft_lstiter, ft_lstmap)

---

## 🏗️ Library Structure

All functions follow the **42 Norm** and are implemented in C. The library is designed to be:
- **Modular**
- **Reusable**
- **Easy to integrate** into other C projects

### Part 1 – Standard C Library Functions

Reimplementations of commonly used functions, including character checks, string handling, memory operations, and conversions.

> ⚠️ **Note:** Some functions like `strlcpy`, `strlcat`, and `bzero` are not included by default in glibc and may require `<bsd/string.h>` and `-lbsd` to test against the system version.

### Part 2 – Additional Functions

Functions not present in standard libc or implemented differently, focusing on **dynamic memory allocation** and safe memory handling:

**String operations:**
- `ft_substr` - Extract substring from string
- `ft_strjoin` - Concatenate two strings
- `ft_strtrim` - Trim characters from both ends
- `ft_split` - Split string by delimiter
- `ft_strmapi` - Apply function to each character (with index)
- `ft_striteri` - Iterate over string with function

**Conversion:**
- `ft_itoa` - Convert integer to string

**File descriptor output:**
- `ft_putchar_fd` - Output character to fd
- `ft_putstr_fd` - Output string to fd
- `ft_putendl_fd` - Output string with newline to fd
- `ft_putnbr_fd` - Output number to fd

### Part 3 – Linked List Functions (Bonus)

Implements a singly linked list (`t_list` structure) to manage dynamic data structures:
```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

**Available operations:**
- `ft_lstnew` - Create new node
- `ft_lstadd_front` - Add node at beginning
- `ft_lstadd_back` - Add node at end
- `ft_lstsize` - Count number of nodes
- `ft_lstlast` - Return last node
- `ft_lstdelone` - Delete single node
- `ft_lstclear` - Delete and free entire list
- `ft_lstiter` - Apply function to each node
- `ft_lstmap` - Apply function and create new list

---

## 🛠️ Compilation

### Build the Library
```bash
make
```

This generates the static library `libft.a` using `cc` with `-Wall -Wextra -Werror`.

### Makefile Rules

| Command | Description |
|---------|-------------|
| `make` or `make all` | Compile the library |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and library |
| `make re` | Rebuild library |
| `make bonus` | Compile with bonus (linked list) functions |

---

## 💻 Usage

### Basic Example
```c
#include "libft.h"

int main(void)
{
    char *str = ft_strdup("Hello, 42!");
    ft_putstr_fd(str, 1);
    free(str);
    return (0);
}
```

**Compile with:**
```bash
cc main.c libft.a
./a.out
```

### Linked List Example
```c
#include "libft.h"

int main(void)
{
    t_list *head = ft_lstnew("First");
    ft_lstadd_back(&head, ft_lstnew("Second"));
    ft_lstadd_back(&head, ft_lstnew("Third"));
    
    // Print list size
    int size = ft_lstsize(head);
    ft_putnbr_fd(size, 1);  // Output: 3
    
    // Clean up
    ft_lstclear(&head, free);
    return (0);
}
```

---

## 🧪 Testing

### Recommended Testers

- [libft-unit-test](https://github.com/alelievr/libft-unit-test)
- [libftTester](https://github.com/Tripouille/libftTester)
- [francinette](https://github.com/xicodomingues/francinette)
- [libft-war-machine](https://github.com/y3ll0w42/libft-war-machine)

### Manual Testing
```bash
# Test with your own main.c
cc -Wall -Wextra -Werror main.c libft.a
./a.out

# Compare with system functions
cc main.c -lbsd  # for strlcpy, strlcat
```

---

## ⚙️ Implementation Notes

### Memory Management

All functions that allocate memory (`ft_strdup`, `ft_substr`, `ft_strjoin`, `ft_split`, `ft_itoa`, etc.) return `NULL` on allocation failure.

The caller is **always responsible** for freeing allocated memory.

### Edge Cases Handled

- `NULL` pointer checks where appropriate
- Empty strings
- Memory allocation failures
- Integer overflow protection (where relevant)
- Proper bounds checking

### Linked List Memory Management

Linked list functions use **function pointers** for content deletion:
```c
void ft_lstdelone(t_list *lst, void (*del)(void *));
void ft_lstclear(t_list **lst, void (*del)(void *));
```

This allows flexible memory management for different content types.

---

## ✅ Norminette Compliance

This project strictly follows the **42 Norm**:
- Maximum 25 lines per function
- Maximum 5 functions per file
- Maximum 4 parameters per function
- No forbidden functions (only standard libc allowed)
- Proper variable declarations
- No variable declarations in the middle of a function
```bash
norminette *.c *.h
# Should return: No errors found
```

---

## 📚 Resources

- [42 Libft Subject](https://cdn.intra.42.fr/pdf/pdf/960/libft.en.pdf)
- Linux man pages (`man 3 function_name`)
- [C programming references](https://en.cppreference.com/w/c)
- [Understanding pointers in C](https://www.tutorialspoint.com/cprogramming/c_pointers.htm)

---

## 🤖 AI Usage

AI tools were used as a learning aid for:
- Understanding function behavior and edge cases
- Explaining C concepts (pointers, memory management, data structures)
- Clarifying standard library function specifications
- **Assistance in writing this README documentation**

**No source code was generated by AI. All implementations are written manually by the author.**

---

## 🎓 Learning Outcomes

This project strengthens understanding of:
- ✅ Dynamic memory allocation (`malloc`, `free`)
- ✅ Pointer arithmetic and manipulation
- ✅ String handling at a low level
- ✅ Data structures (linked lists)
- ✅ Function pointers
- ✅ File descriptor operations
- ✅ Defensive programming in C

**Libft** serves as a foundation for all future 42 projects and can be extended and reused throughout the curriculum.

---

## 📝 License

This project is part of the 42 curriculum and follows the school's academic policies.

---

## 👤 Author

**mucelep** - 42 Network

---

*Made with ☕ at 42*

---
---

## 🇹🇷 TÜRKÇE VERSİYON

## Açıklama

Libft, 42'deki ilk kişisel C kütüphanesi projesidir. Amaç, **standart C kütüphane fonksiyonlarının bir kısmını yeniden yazmak** ve ayrıca **bağlı liste işlemleri** dahil olmak üzere faydalı fonksiyonlar oluşturmaktır.

Bu proje, **hafıza yönetimi, pointer'lar ve düşük seviyeli string işlemleri** konusunda sağlam bir temel oluşturmayı ve modüler, tekrar kullanılabilir kod tasarımını teşvik eder.

---

## 🎯 Amaçlar

- **malloc, free ve pointer kullanımı** konularında derinlemesine bilgi edinmek
- Düşük seviyede **string ve hafıza yönetimi** öğrenmek
- **Tekrar kullanılabilir, iyi yapılandırılmış C fonksiyonları** yazmak
- Mevcut libc implementasyonlarını kullanmadan standart fonksiyonların iç işleyişini anlamak

---

## 📚 Kütüphane Kapsamı

Kütüphane şunları kapsar:
- **Karakter tipi kontrolleri** (isalpha, isdigit, vb.)
- **String işlemleri** (strlen, strlcpy, strlcat, vb.)
- **Hafıza işlemleri** (memset, memcpy, memmove, bzero)
- **Veri dönüştürme** (atoi, itoa)
- **Dosya tanımlayıcılarına çıktı** (putchar_fd, putstr_fd, putendl_fd, putnbr_fd)
- **Bağlı liste işlemleri** (ft_lstnew, ft_lstadd_front/back, ft_lstdelone, ft_lstclear, ft_lstiter, ft_lstmap)

---

## 🏗️ Kütüphane Yapısı

Tüm fonksiyonlar **42 Norm**'a uygun ve C dilinde yazılmıştır. Kütüphane:
- **Modüler**
- **Tekrar kullanılabilir**
- **Diğer C projelerine kolayca entegre edilebilir**

### Bölüm 1 – Standart C Kütüphane Fonksiyonları

Sık kullanılan fonksiyonların yeniden yazımları, karakter kontrolleri, string işlemleri, hafıza işlemleri ve dönüşümleri içerir.

> ⚠️ **Not:** Bazı fonksiyonlar (`strlcpy`, `strlcat`, `bzero`) glibc'de varsayılan olarak bulunmaz ve sistemde test etmek için `<bsd/string.h>` ve `-lbsd` gerekebilir.

### Bölüm 2 – Ek Fonksiyonlar

Standart libc'de bulunmayan veya farklı şekilde uygulanan fonksiyonlar, **dinamik bellek kullanımı** ve güvenli hafıza yönetimi odaklıdır:

**String işlemleri:**
- `ft_substr` - String'den alt string çıkar
- `ft_strjoin` - İki string'i birleştir
- `ft_strtrim` - Her iki uçtan karakter kırp
- `ft_split` - String'i ayırıcıya göre böl
- `ft_strmapi` - Her karaktere (index ile) fonksiyon uygula
- `ft_striteri` - String üzerinde fonksiyonla yinele

**Dönüştürme:**
- `ft_itoa` - Tamsayıyı string'e çevir

**Dosya tanımlayıcı çıktısı:**
- `ft_putchar_fd` - Karakteri fd'ye yazdır
- `ft_putstr_fd` - String'i fd'ye yazdır
- `ft_putendl_fd` - String'i yeni satır ile fd'ye yazdır
- `ft_putnbr_fd` - Sayıyı fd'ye yazdır

### Bölüm 3 – Bağlı Liste Fonksiyonları (Bonus)

Dinamik veri yapılarını yönetmek için tek yönlü bağlı liste (`t_list` yapısı) uygular:
```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

**Mevcut işlemler:**
- `ft_lstnew` - Yeni düğüm oluştur
- `ft_lstadd_front` - Başa düğüm ekle
- `ft_lstadd_back` - Sona düğüm ekle
- `ft_lstsize` - Düğüm sayısını say
- `ft_lstlast` - Son düğümü döndür
- `ft_lstdelone` - Tek düğüm sil
- `ft_lstclear` - Tüm listeyi sil ve temizle
- `ft_lstiter` - Her düğüme fonksiyon uygula
- `ft_lstmap` - Fonksiyon uygula ve yeni liste oluştur

---

## 🛠️ Derleme

### Kütüphaneyi Oluştur
```bash
make
```

Bu komut `cc` ile `-Wall -Wextra -Werror` bayraklarını kullanarak `libft.a` statik kütüphanesini oluşturur.

### Makefile Kuralları

| Komut | Açıklama |
|-------|----------|
| `make` veya `make all` | Kütüphaneyi derle |
| `make clean` | Object dosyalarını sil |
| `make fclean` | Object dosyalarını ve kütüphaneyi sil |
| `make re` | Kütüphaneyi yeniden derle |
| `make bonus` | Bonus (bağlı liste) fonksiyonlarıyla derle |

---

## 💻 Kullanım

### Basit Örnek
```c
#include "libft.h"

int main(void)
{
    char *str = ft_strdup("Merhaba, 42!");
    ft_putstr_fd(str, 1);
    free(str);
    return (0);
}
```

**Derleme:**
```bash
cc main.c libft.a
./a.out
```

### Bağlı Liste Örneği
```c
#include "libft.h"

int main(void)
{
    t_list *head = ft_lstnew("Birinci");
    ft_lstadd_back(&head, ft_lstnew("İkinci"));
    ft_lstadd_back(&head, ft_lstnew("Üçüncü"));
    
    // Liste boyutunu yazdır
    int size = ft_lstsize(head);
    ft_putnbr_fd(size, 1);  // Çıktı: 3
    
    // Temizlik
    ft_lstclear(&head, free);
    return (0);
}
```

---

## 🧪 Test Etme

### Önerilen Test Araçları

- [libft-unit-test](https://github.com/alelievr/libft-unit-test)
- [libftTester](https://github.com/Tripouille/libftTester)
- [francinette](https://github.com/xicodomingues/francinette)
- [libft-war-machine](https://github.com/y3ll0w42/libft-war-machine)

### Manuel Test
```bash
# Kendi main.c dosyanızla test edin
cc -Wall -Wextra -Werror main.c libft.a
./a.out

# Sistem fonksiyonlarıyla karşılaştırın
cc main.c -lbsd  # strlcpy, strlcat için
```

---

## ⚙️ Uygulama Notları

### Bellek Yönetimi

Bellek tahsis eden tüm fonksiyonlar (`ft_strdup`, `ft_substr`, `ft_strjoin`, `ft_split`, `ft_itoa`, vb.) tahsis başarısızlığında `NULL` döner.

Tahsis edilen belleği temizlemek **her zaman çağıran kodun sorumluluğundadır**.

### İşlenen Özel Durumlar

- Uygun yerlerde `NULL` pointer kontrolleri
- Boş string'ler
- Bellek tahsis hataları
- Tamsayı taşma koruması (ilgili yerlerde)
- Doğru sınır kontrolleri

### Bağlı Liste Bellek Yönetimi

Bağlı liste fonksiyonları içerik silme için **fonksiyon pointer'ları** kullanır:
```c
void ft_lstdelone(t_list *lst, void (*del)(void *));
void ft_lstclear(t_list **lst, void (*del)(void *));
```

Bu, farklı içerik tipleri için esnek bellek yönetimi sağlar.

---

## ✅ Norminette Uyumluluğu

Bu proje **42 Norm**'una kesinlikle uygundur:
- Fonksiyon başına maksimum 25 satır
- Dosya başına maksimum 5 fonksiyon
- Fonksiyon başına maksimum 4 parametre
- Yasak fonksiyon yok (sadece standart libc izinli)
- Uygun değişken bildirimleri
- Fonksiyon ortasında değişken bildirimi yok
```bash
norminette *.c *.h
# Şunu dönmeli: No errors found
```

---

## 📚 Kaynaklar

- [42 Libft Konusu](https://cdn.intra.42.fr/pdf/pdf/960/libft.en.pdf)
- Linux man sayfaları (`man 3 fonksiyon_adı`)
- [C programlama referansları](https://en.cppreference.com/w/c)
- [C'de pointer'ları anlamak](https://www.tutorialspoint.com/cprogramming/c_pointers.htm)

---

## 🤖 Yapay Zeka Kullanımı

Yapay zeka araçları öğrenme aracı olarak kullanıldı:
- Fonksiyon davranışlarını ve özel durumları anlama
- C kavramlarını açıklama (pointer'lar, bellek yönetimi, veri yapıları)
- Standart kütüphane fonksiyon özelliklerini netleştirme
- **Bu README dokümantasyonunun yazılmasında yardımcı olma**

**Hiçbir kaynak kodu yapay zeka tarafından üretilmemiştir. Tüm uygulamalar yazar tarafından manuel olarak yazılmıştır.**

---

## 🎓 Öğrenme Kazanımları

Bu proje şu konularda anlayışı güçlendirir:
- ✅ Dinamik bellek tahsisi (`malloc`, `free`)
- ✅ Pointer aritmetiği ve manipülasyonu
- ✅ Düşük seviyede string işleme
- ✅ Veri yapıları (bağlı listeler)
- ✅ Fonksiyon pointer'ları
- ✅ Dosya tanımlayıcı işlemleri
- ✅ C'de savunmacı programlama

**Libft**, tüm gelecekteki 42 projeleri için bir temel oluşturur ve müfredat boyunca genişletilebilir ve yeniden kullanılabilir.

---

## 📝 Lisans

Bu proje 42 müfredatının bir parçasıdır ve okulun akademik politikalarını takip eder.

---

## 👤 Yazar

**mucelep** - 42 Network

---

*42'de ☕ ile yapıldı*
