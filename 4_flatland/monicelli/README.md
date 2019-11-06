# Flatland in Monicelli

## Cos'è Flatland e Monicelli
Per maggiori informazioni su Monicelli consultare: https://github.com/esseks/monicelli

Per maggiori informazioni su Flatland consultare: https://github.com/NicolaToscan/ASD_1920/tree/master/4_flatland
## I file
| Nome File | Description |
| ----------- | ----------- |
| [monicelli_flatland.mcc](https://github.com/NicolaToscan/ASD_1920/blob/master/4_flatland/monicelli/monicelli_flatland.mcc) | Versione scritta in monicelli con i nomi delle variabili comprensibili |
| [monicelli_flatland_named.mcc](https://github.com/NicolaToscan/ASD_1920/blob/master/4_flatland/monicelli/monicelli_flatland_named.mcc) | Versione scritta in monicelli con i nomi delle variabili a tema |
| [monicelli_flatland_mapping.txt](https://github.com/NicolaToscan/ASD_1920/blob/master/4_flatland/monicelli/monicelli_flatland_mapping.txt) | Mapping della versione monicelli in pseudo c++ |
| [monicelli_flatland_mcc_mapped.mcc](https://github.com/NicolaToscan/ASD_1920/blob/master/4_flatland/monicelli/monicelli_flatland_mcc_mapped.mcc) | Versione scritta in monicelli affiancata al mapping |

## Come funziona
Per poter scrivere il programma in monicelli sono dovuto scendere a dei compromessi:
- L'input dei dati sarà chiesto due volte
- L'output dei valori rimanenti sarà dato contemporaneamente all'inserimento

Dopo aver lanciato l'eseguibile dare in input i valori nel seguente ordine:
- Numero di triangoli nella sequenza
- Uno alla volta il verso dei triangoli usando 1 per sinistra e 0 per destra (la fine dell'inserimento del primo set di input sarà indicata con l'output di `8888888`)
- Ripetere il passo precedente

Durante il secondo inserimento verranno stampati i valori che compongono la soluzione preceduti da 1000 per essere meglio notati

## Compilazione
I file monicelli possono essere compilati in un container Docker.

Per avviare il container si può usare il [DockerFile](https://github.com/NicolaToscan/ASD_1920/blob/master/4_flatland/monicelli/Dockerfile) presente nella repository nel seguente modo:

```
docker build -t monicelli .
docker run --rm -it -v /path/to/local/folder:/data monicelli
```

Ora nella directory `/data` si potranno vedere i file presenti nella cartella locale e compilarli con

```
mcc nomefile.mcc
```
