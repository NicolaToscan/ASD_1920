# FLATLAND
Si presuppone la conoscienza del problema illustrato [qui](https://github.com/NicolaToscan/ASD_1920/blob/master/4_flatland/flatland%20(it).pdf).

## Notazione e terminologia
| Simbolo | Description |
| ----------- | ----------- |
| X | Testa o coda della sequenza |
| --- | Insieme di N  triangoli |
| < | Traingolo che punta a sinistra |
| > | Traingolo che punta a destra |
| T | Traingolo generico |

| Termine | Significato |
| ----------- | ----------- |
| RIDUZIONE | Eliminazione di due triangoli come illustrato nelle regole |
| SEQUENZA RIDUCIBILE | La sequenza può essere portata a lunghezza 0 dopo un certo numero di riduzioni senza l'eliminazione di elementi esterni alla sequenza

La struttura di una qualunquesequnza sarà dunque:

`X --- X`

## Teorema
In una sequenza `X --- T --- X`, con `T` può appartenere alla soluzione se e solo se `X---` e `---X` possono entrambi essere riducibile indipendentemente.

`X ---` è riducibile se e solo se:
1. `X---` è un numero pari di triangoli
2. `X ---` è in una delle seguenti forme:
   - `X --- <`
   - `X --- <> --- <` con `---` numero pari di triangoli

(Uguale per simmetria su `--- X`).

## Dimostrazione
<!-- dim che devono essere eliminate ind. -->

### 1. Se `X---` non è pari T non appartine alla soluzione
Ipotizando per assurdo che `X---` è formato da 2n + 1 triangoli, tentando di ridurre n volte si possono verificare le seguenti condizioni:
- Impossibile eseguire una riduzione su `X---`
- Dopo n eliminazioni si rimane con un solo triangolo che non può essere eliminato

In entrambi i casi è impossibile ridurre completamente la sequenza.


### 2a. Se nella forma `X --- <` è  sempre riducibile
La sequenza è nella forma `X --- <` con `---` numero N pari di triangoli per (1).

**Se N = 0** `X<` è riducibile.

**Se N >= 2** analizando gli ultimi 3 triangoli di `X---<` si può applicare una delle seguenti riduzioni:
| Forma iniziale | Forma dopo riduzione |
| ----------- | ----------- |
| `X---<<<` | `X---<` |
| `X---<><` | `X---<` |
| `X---><<` | `X---<` |
| `X--->><` | `X---<` |

Procedendo cosi N/2 volte si raggiungerà il caso N = 0 e dunque abbiamo una possibile serie di riduzione che risolvono la sottosequenza.

### 2b. Se nella forma `X---<>--->` con --- pari è sempre eliminabile
Se la sequenza presenta `X---<>--->` con `---` pari, dividiamo il problema cercando di eliminare `X---<` e `>---<`.
- `X----<` risolvibile per (2a).
- `>--->` può essere visto come `>---X` e dunque risolvibile per simmetria di (2a).

Quindi la forma `X---<>--->` è sempre eliminabile.


### Se (2a) o (2b) non presenti non risolvibile
Se la sequenza non presenta `X---<>--->` e `X---<` possiamo raffigurarla con `X--->` con `---` N pari di triangoli.

**Se N = 0** si ha `X>` che è impossibile.

**Se N = 2** possiamo avere

|   | Forma iniziale | Tutte le possibile semplificazione | Risultato finale |
| - | ----------- | ----------- | ----------- |
| 1 | `X<<>` | `X>`, `<>` | Impossibile da risolvere |
| 2 | `X<>>` | `>>`, `X<` | Possibile da risolvere |
| 3 | `X><>` | `X>` | Impossibile da risolvere |
| 4 | `X>>>` |  `X>` | Impossibile da risolvere |

L'unica disposizione che porta ad una soluzioe è la 2, ma deve essere esclusa perchè nella forma `X---<>--->`.

**Se N >= 4**
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

Dopo N/2 - 1 riduzioni raggiungeremmmo la forma con N = 2, ma dato che nessuna delle riduzioni precedenti porta < `<>` sarà impossibile raggiungere la forma `X<>>` necessaria per la soluzione