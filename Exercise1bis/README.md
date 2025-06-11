# 🟢 Esercizio 1BIS – LED Blinking non bloccante

## 🎯 Obiettivo

In questo esercizio, lo studente realizzerà un lampeggio continuo del LED integrato (`LED_BUILTIN`) **senza utilizzare la funzione `delay()`**, ma affidandosi a una gestione del tempo basata sul clock interno della piattaforma Arduino.

L’obiettivo è comprendere **le limitazioni dell’attesa attiva** (`busy-wait`) imposta da `delay()` e **i vantaggi dell'approccio non bloccante** basato su polling del tempo corrente. Il comportamento del LED dovrà quindi essere regolato usando il metodo `blink()` della classe `Led`, che si occupa autonomamente di verificare quando è il momento giusto per invertire lo stato del LED.

## 📚 Competenze sviluppate

- Comprendere il concetto di **busy-wait** e perché `delay()` blocca l'intero flusso del programma.
- Utilizzare `micros()` per una gestione precisa del tempo.
- Sviluppare un ciclo `loop()` responsivo, pronto per ospitare future funzionalità concorrenti.

## 🧱 Requisiti hardware

| Componente      | Quantità | Note                                  |
|-----------------|----------|---------------------------------------|
| Arduino UNO     | 1        | Con LED integrato su pin 13 (`LED_BUILTIN`) |
| Cavo USB        | 1        | Per collegamento e alimentazione      |

## 💻 Requisiti software

- **Arduino IDE** installato (versione consigliata ≥ 1.8.19)
- Ambiente operativo configurato per la compilazione su Arduino UNO

## 📦 File forniti

- `led.hpp`: header aggiornato della classe `Led`, con supporto per blinking autonomo
- `led.cpp`: implementazione conforme a MISRA C:2012 della logica di blinking non bloccante

> ⚠️ Anche in questo esercizio **non viene fornito il file `.ino`**. Lo studente dovrà implementarlo seguendo le istruzioni.

## 🔧 Istruzioni operative

1. **Importare i file `led.hpp` e `led.cpp`** nella cartella dello sketch.
2. **Scrivere un file `.ino`** in cui:
   - Viene creata un’istanza `Led` per il pin `LED_BUILTIN`.
   - Nel `setup()` si configura la frequenza di lampeggio desiderata (es. 1000 ms).
   - Nel `loop()` si richiama periodicamente `user_led.blink()`.

3. **Compilare e caricare lo sketch** sulla scheda Arduino UNO.
4. **Osservare il comportamento del LED**: deve lampeggiare esattamente come prima, ma il codice ora non è più bloccante.

## ✏️ Estensione proposta

Aggiungere al `loop()` altre operazioni (es. stampa sul monitor seriale, lettura di un pin, controllo di un pulsante) per osservare come il LED continui a lampeggiare **senza interferenze**, a differenza di quanto accadrebbe con `delay()`.

## 🔬 Concetti chiave

| Concetto                   | `delay()`                      | `blink()` (non bloccante)        |
|----------------------------|--------------------------------|----------------------------------|
| Blocco esecuzione          | ✅ sì                           | ❌ no                             |
| Precisione sotto 1 ms      | ❌ limitata                     | ✅ possibile tramite `micros()`  |
| Multitasking cooperativo   | ❌ ostacolato                   | ✅ facilitato                     |
| Reattività a eventi esterni| ❌ compromessa                  | ✅ mantenuta                      |

## 📌 Nota didattica

Questo esercizio costituisce una **svolta concettuale** nella didattica embedded: dallo stile sequenziale sincrono si passa a una logica **basata su controllo del tempo** e su **funzioni non bloccanti**, necessaria per progetti futuri con sensori, attuatori multipli e comunicazioni.

---

© 2025 – Alessio Guarini  
PhD Student in Connected Autonomous Vehicles  
MIVIA Lab, Università degli Studi di Salerno  
[aguarini@unisa.it](mailto:aguarini@unisa.it)