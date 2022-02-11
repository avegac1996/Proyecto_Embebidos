import React, { Component } from "react";
import img1 from "../../resources/img/foto1.jpg";
import img2 from "../../resources/img/foto2.png";

class QuienesSomos extends Component {
  render() {
    return (
      <div class="container">
        <br />
        <h1 class="text-center estilo-fuente">UNIVERSIDAD POLITÉCNICA SALESIANA
        </h1>
        <br />

        <h2 className="estilo-fuente">Introducción Proyecto Final</h2>
        <p class="lh-lg">
          El desarollo de este proyecto es una simulación del canal de panama el cual
          es interpretado para predecir  la distancia de los buques al puerto, como tambien para
          predecir el aumento de temperatura como humedad tanto para el control y prevención de accidentes.
          <br></br>


          Un Sistema Embebido es un sistema electronico diseñado para realizar pocas funciones en tiempo real,
          segun sea el caso. Al contrario de lo que ocurre con las computadoras, las cuales tienen un proposito
          general, ya que estan diseñadas para cubrir un amplio rango de necesidades y los Sistemas Embebidos
          se diseñan para cubrir necesidades especificas.
          En un Sistema Embebido la mayoria de los componentes se encuentran incluidos en la placa base
          (la tarjeta de video, audio, modem) y muchas veces los dispositivos resultantes no tienen el aspecto
          de lo que se suele asociar a una computadora. Algunos ejemplos de Sistemas Embebidos podrian
          ser dispositivos como un taximetro, un sistema de control de acceso, la electronica que controla una
          maquina expendedora o el sistema de control de una fotocopiadora entre otras multiples aplicaciones.
        </p>

        <img src={img1} alt="img1" width="900" height="600" className="rounded mx-auto d-block" />
        <br />

        <h2 className="estilo-fuente">Visión</h2>
        <p class="lh-lg">
          Tenemos como finalidad producir datos confiables sobre la distancia que se encuentra
          un barco, hacia nuestros sensores tomando acciones al mejoramiento de canal y difundir esta información, al público en general.
        </p>

        <ul class="list-group">
          <li class="list-group-item active" aria-current="true">
            Quienes Somos
          </li>
          <li class="list-group-item"> Estudiantes de la Universidad Politécnica Salseiana
            carrera</li>
          <li class="list-group-item">Ingeniería en Ciencias de la Computación</li>
          <li class="list-group-item active" aria-current="true">
            INTEGRANTES
          </li>
          <li class="list-group-item">VEGA CRUZ ANTHONY JHOSSUA
            avegac@est.ups.edu.ec</li>
          <li class="list-group-item">Topón Guallichico Jefferson Andrés
            jtopong1@est.ups.edu.ec</li>
          <li class="list-group-item">Granda Flores Jhon freddy
            jgrandaf@est.ups.edu.ec</li>
          <li class="list-group-item">Borja Hernández Fabricio Alexander
            fborjah@est.ups.edu.ec</li>
          <li class="list-group-item">
            Alex Catota
            acatota@est.ups.edu.ec
          </li>
        </ul>
        <ul class="list-group">
          <li class="list-group-item active" aria-current="true">
            Versión
          </li>
          <li class="list-group-item">Versión estable más reciente 1.1</li>
          <li class="list-group-item"></li>
          <li class="list-group-item"></li>
          <li class="list-group-item"></li>
        </ul>
        <ul class="list-group">

        </ul>
        <br />
      </div>
    );
  }
}

export default QuienesSomos;
