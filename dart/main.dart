import 'dart:io';
import 'dart:math';
import 'dart:convert';
import 'dart:async';

void crearPuntajes(File puntajes){
  print("Se estan creando los puntajes ... Espere un momento por favor");
  Random random = new Random();   
  for (var i = 14000000; i <=14001000; i++) {   //Ciclo en el cual se crearan los puntajes
    int NEM = 475 + random.nextInt(276);
    int RKN = 475 + random.nextInt(276);
    int MAT = 475 + random.nextInt(276);
    int LEN = 475 + random.nextInt(276);
    int CIE = 475 + random.nextInt(276);
    int HIS = 475 + random.nextInt(276);
    puntajes.writeAsStringSync("${i};${NEM};${RKN};${MAT};${LEN};${CIE};${HIS}\r\n", mode:APPEND); //Escritura sobre el archivo puntajes
    
    
  }
  print("Se han creado los puntajes");
}
void crearpromedios(File promedio)
{
  print("Se esta calculando el promedio...");
  final archivo = new File('puntajes.csv');
  Stream<List<int>> inputStream = archivo.openRead();

 

  inputStream
    .transform(utf8.decoder)       // Decode bytes to UTF-8.
    .transform(new LineSplitter()) // Convert stream to individual lines.
    .listen((String linea) {        // Process results.
        double promedios;
        var separar = linea.split(";");
        String rut = separar[0];
        double nem = double.parse(separar[1]);
        double ranking = double.parse(separar[2]);
        double matematica = double.parse(separar[3]);
        double lenguaje = double.parse(separar[4]);
        double ciencia = double.parse(separar[5]);
        double historia = double.parse(separar[6]);
        promedios=(nem+ranking+matematica+lenguaje+ciencia+historia)/6;

        promedio.writeAsStringSync("${rut};${promedios}\r\n", mode:APPEND);
        
        
      },
      onDone: () { print('File is now closed.'); },
      onError: (e) { print(e.toString()); });

}


void main(){ 
  File promedios= new File("promedios.csv"); //Creación del archivo llamado promedios.
  File puntajes = new File("puntajes.csv"); //Creación del archivo llamado puntajes.
  crearPuntajes(puntajes);
  crearpromedios(promedios);
  
}
