# FLATLAND

## Notazione
| Simbolo | Description |
| ----------- | ----------- |
| X | Testa o coda della sequenza |
| --- | Insieme di N  triangoli |
| < | Traingolo che punta a sinistra |
| > | Traingolo che punta a destra |
| O | Elemento di cui voglio verificare se rimane |

La struttura di una sequnza sarà dunque:

`X --- O --- X`

## Teorema
In una sequenza `X --- O --- X`, `O` può rimanere se e solo se `X---` e `---X` possono essere eliminati indipendentemente.

`X ---` è eliminabile se e solo se:
1. `X---` è un numero pari di triangoli
2. `---` è in una delle seguenti forme:
   - `---<`
   - `--- <> ---` con `---` numero pari di triangoli

`--- X` verificabile come prima per simmetria.

## Dimostrazione

### 1. `X---` numero pari
Per assurdo `X---` è un numero 2n + 1 di triangoli, riduco n volte in modo arbitrario, deve essere sempre possibile rimuovere due elementi.

Dopo n passaggi si raggiungerà una lunghezza di 1 che è impossibile da eliminare perchè solo.

### 2a. `X --- <`  sempre eliminabile
La sequenza è nella forma `X --- <` con `---` numero N pari di triangoli

Se N = 0 allora si ha `X<` che è sempre eliminabile

Se N >= 2 analizando gli ultimi 3 elementi si ha:

| Forma iniziale | Possibile semplificazione |
| ----------- | ----------- |
| `<<<` | `<` |
| `<><` | `<` |
| `><<` | `<` |
| `>><` | `<` |

Ridudcendolo a N - 2

Si può dunque ripetere fino a raggingere N = 0, ed è quindi sempre risolvibile

### 2b. `X ---- <> ---`  sempre eliminabile
Se la sequenza presenta `X ---- <> ---` con `----` pari e `---` dispari,possimao dividere il problema cercando di eliminare `X----<` e `>---` con entrami numero pari di triangoli.
- `X----<` risolvibile per (2a)
- `>---` può essere visto come `>---X` e dunque risolvibile per simmetria di (2a)

Quindi la forma `X ---- <> ---` è sempre eliminabile


### 3. `X ---- <> ---` e `X --- <`  non presenti
Se la sequenza non presenta `X ---- <> ---` e `X --- <` possiamo raffigurarla con `X--->` con `---` N pari di triangoli

Se N = 0 si ha `X>` che è impossibile

Se N = 2 possiamo avere

| Forma iniziale | Tutte le possibile semplificazione | Risultato finale |
| ----------- | ----------- | ----------- |
| `X<<>` | `X>`, `<>` | Impossibile da risolvere |
| `X<>>` | `>>`, `X<` | POssibile da risolvere |
| `X><>` | `X>` | Impossibile da risolvere |
| `X>>>` |  `X>` | Impossibile da risolvere |

Se N >= 4
Per essere risolvibile deve essere ridotto a `X<>>`
Se riusciamo ad ottenere un `X ---- <> ---` puo essere mantenuto fino ad ottenere `X<>>` e quindi la soluzione.

Prendendo una qualunque parte della sequenza di 4 elementi del tipo: `X---ABCD--->` dove `AB != <>` e `CD != <>` per ipotesi
si può ridurre nel seguente modo:

| Forma iniziale | Tutte le possibile semplificazione |
| ----------- | ----------- |
| `>>>>` | `>>` |
| `>><<` | `>>`, `<<`, `><` |
| `>>><` | `>>`, `><`|
| `<<>>` | `>>`, `<<` |
| `<<<<` | `<<` |
| `<<><` | `><`, `<<` |
| `><>>` | `>>`, `><` |
| `><<<` | `<<`, `><` |
| `><><` | `><` |

In nessun caso è possibile ottenere un `<>` e ripetendo per abbastanza volta sarà impossibile raggiungere la forma `X<>>` per risolvere la sequenza