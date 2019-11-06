# Flatland in Monicelli

## Cos'è monicelli
Per maggiori informazioni su Monicelli consultare: https://github.com/esseks/monicelli

## Compilazione
I file monicelli possono essere compilati in un container Docker.

Per avviare il container si può usare:

```
docker build -t monicelli .
docker run --rm -it -v /path/to/local/folder:/data monicelli
```

Ora nella directory `/data` si potranno vedere i file presenti nella cartella locale e compilarli con

```
mcc nomefile.mcc
```
