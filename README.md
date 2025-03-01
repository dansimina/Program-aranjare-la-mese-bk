# 🚀 Sistem de Aranjare la Mese

Acest repository conține o **implementare în C++** a unui algoritm care **distribuie optim persoanele la mese** în funcție de **numărul de locuri disponibile, relațiile de antipatie și siamezii**. Programul ia în considerare **restricțiile (antipatii)** și **siamezii care trebuie să fie la aceeași masă** pentru a genera o **distribuție validă a locurilor**.

---

## 📜 Prezentare Generală a Proiectului

### 🏗️ Problema
Dat fiind un **grup de persoane**, programul trebuie să țină cont de următoarele:
- **Un număr limitat de mese**, fiecare cu un număr fix de locuri.
- **Relații de antipatie** (persoane care nu trebuie să stea la aceeași masă).
- **Siamezi** (persoane care trebuie să stea la aceeași masă).

Programul determină **o distribuție optimă a locurilor**, respectând aceste constrângeri.

---

### 🔍 Funcționalități

- **Adăugarea și gestionarea persoanelor**:
  - Adăugarea unei persoane cu **nume, antipatii și siamezi**.
  - Modificarea **relațiilor existente**.
  - Ștergerea unei persoane din baza de date.

- **Generarea aranjamentului la mese**:
  - Folosește un **algoritm de backtracking** pentru distribuirea persoanelor la mese.
  - Se asigură că **persoanele antipatice sunt separate**, iar **siamezii sunt la aceeași masă**.
  - Dacă se găseȟte o soluție validă, **se salvează alocările în fișiere**.

- **Gestionarea și persistența datelor**:
  - Salvează și încarcă **informațiile despre persoane** dintr-un fișier (`date.txt`).
  - Permite modificări dinamice ale **antipatiilor și siamezilor**.
  - **Sistem de backup** pentru prevenirea pierderii datelor.

- **Meniu interactiv și ușor de utilizat**:
  - Folosește un **meniu bazat pe comenzi** pentru gestionarea datelor.
  - Navigare interactivă cu **tastatura** pentru adăugarea și modificarea datelor.

---

## 🛠️ Implementarea Algoritmului

Programul utilizează **backtracking** pentru a determina cea mai bună distribuție a locurilor.

### 🏗️ Etapele Algoritmului:
1. **Preprocesare**:
   - Se citește inputul din `date.txt` (dacă este disponibil).
   - Se analizează **restricțiile de antipatie și siamezi**.

2. **Propagarea Constrângerilor**:
   - Persoanele sunt grupate în **clustere** pe baza siamezilor.
   - Persoanele cu **conflicte sunt izolate** în grupuri separate.

3. **Atribuirea Locurilor cu Backtracking**:
   - Se atribuie persoane la **mese**, respectând toate constrângerile.
   - Dacă o masă este **completă**, se trece la următoarea.
   - Dacă o persoană **nu poate fi așezată**, algoritmul revine la pasul anterior și încearcă altă distribuție.

4. **Generarea Rezultatului**:
   - Dacă există o soluție validă, aceasta este **salvată în fișiere text** (`masa1.txt`, `masa2.txt` etc.).
   - Dacă nu există o soluție posibilă, utilizatorul este **informat că nu se poate realiza aranjamentul**.

---

## 🎮 Controale și Funcționalități

| Acțiune | Funcție |
|---------|--------|
| Adăugare persoană | Introduce un **nume, antipatii și siamezi** |
| Modificare persoană | Schimbă **numele, antipatiile sau siamezii** |
| Ștergere persoană | Elimină o persoană din baza de date |
| Generare aranjament | Rulează **algoritmul de distribuție** |
| Afișare antipatici | Arată toate **perechile incompatibile** |
| Afișare siamezi | Arată toate **perechile care trebuie să stea la aceeași masă** |
| Salvare & Ieșire | Salvează datele în `date.txt` pentru sesiuni viitoare |

---

## 📌 Considerații de Performanță
- **Backtracking optimizat** pentru a minimiza calculele inutile.
- **Stocare eficientă a relațiilor** folosind **liste de adiacență**.
- **Euristici de preprocesare** pentru **reducerea spațiului de căutare** înainte de începerea alocării.

