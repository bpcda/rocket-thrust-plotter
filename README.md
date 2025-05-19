# Rocket Thrust Logger
Sistema integrato per la registrazione e la visualizzazione della spinta generata da un razzo modellino.
Il progetto combina componenti meccanici stampati in 3D (file STL), sensori connessi a una scheda Arduino e un modulo di acquisizione dati, producendo grafici dell’impulso in tempo reale o esportabile.
Sviluppato per test didattici e modellistici.

---

## 🎯 Motivazione

Il progetto nasce dalla necessità di ottenere un grafico **forza/tempo (impulso)** reale di un motore per razzo modellino, da poter poi importare in **OpenRocket**.  
Questo permette di **simulare con precisione la traiettoria**, la **stabilità aerodinamica** e la **distanza di volo** in funzione del motore realmente utilizzato.

---

## ⚙️ Funzionamento

Il sistema è tecnicamente semplice ma funzionale:

- Una **cella di carico** misura la spinta del motore
- Il segnale è amplificato con un **HX711**
- Un **Arduino** legge i dati e li invia per il **plotting in tempo reale**
- I dati vengono raccolti per generare un grafico impulso/tempo (thrust curve)

Il supporto per il motore e la struttura per la cella di carico sono stampati in 3D e inclusi nei file STL del progetto.

---

## 🚀 Tecnologie

- Arduino (Nano o Uno)
- HX711 (amplificatore per celle di carico)
- Cella di carico da 5–10kg
- Software plotting (es. SerialPlot o custom)
- OpenRocket (per la simulazione post-raccolta dati)
- STL stampabili per il supporto struttura

---


## 🛡️ Licenza

Questo progetto è distribuito sotto licenza **Creative Commons Attribution 4.0 International (CC BY 4.0)**.

Puoi copiarlo, modificarlo e utilizzarlo anche a fini commerciali, a condizione che venga citata la fonte originale.

🔗 [Visualizza la licenza](https://creativecommons.org/licenses/by/4.0/)
