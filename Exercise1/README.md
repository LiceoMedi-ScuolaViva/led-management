# 🟢 Esercizio 1 – LED Blinking base

## 🎯 Obiettivo

In questo primo esercizio, lo studente imparerà a far lampeggiare (blinking) un LED collegato alla scheda **Arduino UNO**, utilizzando un approccio a oggetti mediante la classe `Led` fornita. L'attività ha lo scopo di introdurre la struttura di base di un firmware embedded e il concetto di attuatore digitale.

## 📚 Competenze sviluppate

- Comprendere la struttura di un firmware Arduino (`setup()` / `loop()`).
- Utilizzare la funzione `delay()` per temporizzare eventi.
- Applicare i fondamenti della programmazione a oggetti in C++ in un contesto embedded.
- Compilare e caricare uno sketch su una scheda Arduino attraverso l'IDE.

## 🧱 Requisiti hardware

| Componente      | Quantità | Note                                  |
|-----------------|----------|---------------------------------------|
| Arduino UNO     | 1        | Con LED integrato su pin 13 (`LED_BUILTIN`) |
| Cavo USB        | 1        | Per collegamento e alimentazione      |

## 💻 Requisiti software

- **Arduino IDE** installato (versione consigliata ≥ 1.8.19)
- Ambiente operativo configurato per la compilazione su Arduino UNO
- Monitor seriale opzionalmente attivabile per debugging

## 📦 File forniti

- `led.hpp`: definizione della classe `Led`
- `led.cpp`: implementazione della classe `Led`

> ⚠️ **Non viene fornito il file `.ino`.** Lo studente dovrà implementarlo a partire dalle specifiche fornite durante la lezione.

## 🔧 Istruzioni operative

1. **Importare i file `led.hpp` e `led.cpp`** all'interno della cartella dello sketch.
2. **Scrivere un file `.ino`** in cui:
   - Viene inclusa la classe `Led`.
   - Viene creata un’istanza di `Led` associata al pin `LED_BUILTIN`.
   - Viene implementato un lampeggio continuo con una frequenza temporizzata tramite `delay()`.

3. **Compilare e caricare lo sketch** sulla scheda Arduino UNO.
4. **Osservare il comportamento del LED**: deve lampeggiare a intervalli regolari.

## ✏️ Estensione proposta

Modificare la frequenza del lampeggio:
- Rallentare o velocizzare il ciclo di blinking cambiando il valore di `delay()`.

## 📌 Nota didattica

Questo esercizio introduce implicitamente il concetto di **ciclo a tempo fisso** tipico dei firmware real-time, anche se implementato con `delay()` per semplicità. In ambienti embedded più avanzati, il controllo temporale avviene con timer hardware o polling su timestamp, ma l’uso di `delay()` resta fondamentale per introdurre l’idea di **scheduling deterministico**.

---

© 2025 – Alessio Guarini  
PhD Student in Connected Autonomous Vehicles  
MIVIA Lab, Università degli Studi di Salerno  
[aguarini@unisa.it](mailto:aguarini@unisa.it)