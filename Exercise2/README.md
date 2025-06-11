# 🔵 Esercizio 2 – Cambia la frequenza di blinking del LED

## 🎯 Obiettivo

Questo esercizio guida lo studente nell’interazione con il sistema embedded attraverso la **seriale**, mostrando come sia possibile modificare la frequenza di lampeggio del LED integrato (`LED_BUILTIN`) **tramite la pressione di tasti sulla tastiera del PC**.

L’attività mira a consolidare il concetto di **input asincrono** e a far comprendere come sia possibile progettare un firmware reattivo agli eventi, senza interrompere il comportamento ciclico di lampeggio.

## 📚 Competenze sviluppate

- Utilizzo del **monitor seriale** dell’Arduino IDE
- Lettura non bloccante da `Serial.read()` e `Serial.available()`
- Gestione di una variabile numerica tramite comandi da tastiera
- Integrazione tra blinking autonomo e input esterno

## 🧱 Requisiti hardware

| Componente      | Quantità | Note                                          |
|-----------------|----------|-----------------------------------------------|
| Arduino UNO     | 1        | Con LED integrato su pin 13 (`LED_BUILTIN`)   |
| Cavo USB        | 1        | Per collegamento e alimentazione              |

## 💻 Requisiti software

- **Arduino IDE** installato (versione consigliata ≥ 1.8.19)
- Monitor seriale abilitato
- File `led.hpp` e `led.cpp` già inclusi nel progetto

> ⚠️ Come nei precedenti esercizi, **non viene fornito il file `.ino`**. Gli studenti dovranno implementarlo in autonomia seguendo lo schema proposto a lezione.

## 📦 Comportamento atteso

1. All’avvio, il LED lampeggia con un periodo iniziale di **500 ms**.
2. Se l’utente preme il tasto `'+'`, il periodo di lampeggio diminuisce (frequenza aumenta).
3. Se l’utente preme il tasto `'-'`, il periodo di lampeggio aumenta (frequenza diminuisce).
4. Il valore del periodo è **limitato tra 50 ms e 2000 ms** tramite una funzione `__clamp(...)`.
5. Il valore aggiornato viene visualizzato sul **monitor seriale**.

## 🔧 Istruzioni operative

1. **Preparare la struttura dello sketch**:
   - Includere la classe `Led`
   - Definire una variabile `blink_period_ms`
   - Implementare la funzione `__clamp(...)` per limitare il range del periodo

2. **Scrivere il codice Arduino**:
   - In `setup()`: inizializzare la seriale e impostare il periodo iniziale
   - In `loop()`: richiamare `blink()`, leggere da `Serial`, aggiornare il periodo

3. **Collegare l’Arduino al PC** e aprire il monitor seriale.
4. **Testare l’interazione** premendo i tasti `'+'` e `'-'`.

## 💡 Approfondimenti

- Questo esercizio è un primo esempio di **interfaccia utente seriale**, utile per controllare i parametri di runtime nei sistemi embedded.
- La lettura seriale non blocca il funzionamento del `loop()` perché è condizionata da `Serial.available() > 0`.
- Il sistema è reattivo e può essere facilmente esteso con comandi più complessi (menu, parsing di stringhe, ecc.).

## ✏️ Estensione proposta

Implementare anche i seguenti tasti:
- `'o'`: spegne il LED (chiama `off()`)
- `'i'`: accende il LED (chiama `on()`)
- `'t'`: esegue un singolo `toggle()`
- `'r'`: ripristina il periodo iniziale a 500 ms

## 📌 Nota didattica

L'interazione con il monitor seriale rappresenta un **ponte tra il mondo digitale del PC e quello embedded** della scheda Arduino. Questa modalità di controllo è ampiamente usata anche in contesti professionali per debugging, configurazione remota, telemetria e diagnostica.

---

© 2025 – Alessio Guarini  
PhD Student in Connected Autonomous Vehicles  
MIVIA Lab, Università degli Studi di Salerno  
[aguarini@unisa.it](mailto:aguarini@unisa.it)