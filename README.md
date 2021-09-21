# Trabajo Experimental Análisis de Algoritmos
Repositorio del código fuente y paper del trabajo experimental sobre el tiempo de ejecución de un algoritmo de cálculo de determinante de una matriz de orden n.

Lenguaje usado: C++

Integrantes:
<ul>
  <li>Germán Contreras Améstica</li>
  <li>Lucas Corco Schnake</li>
</ul>

## Requisitos

  <ul>
    <li> Sistema Operativo basado en Linux </li>
    <li> GCC 11.1.10 </li>
    <li> Make </li>
  </ul>

### Instalando GCC y Make en distros basadas en ubuntu
```
$ sudo apt-get install build-essential

```
## Instrucciones: 
 
 Abra la terminal y posiciónese en la carpeta app

```
$ cd /app
```

Luego ejecute el makefile

```
$ makefile

```
el programa compilará y el binario se encontrará en app/dist.

Finalmente ejecute el programa

```
$ cd /dist

$ ./determinante [dimension] [inferior] [superior]

```

### Ejecutando el test automatizado

Para ejecutar el test automatizado ubíquese en la carpeta raíz del proyecto y ejectute <strong>tests.sh</strong>

```
$ sh tests.sh

```

Esto generará el archivo <strong>tests.sh</strong> y se guardará en app/dist