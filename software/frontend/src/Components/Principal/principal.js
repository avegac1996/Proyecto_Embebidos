import React, { Component } from "react";

import img1 from "../../resources/img/foto1.jpg";
import img2 from "../../resources/img/foto2.png";
import RadiacionSolar from "../RadiacionSolar/RadiacionSolar";
import RadiacionSolarCommands from "../RadiacionSolar/RadiacionSolarCommands";


class principal extends Component {
    render() {
        return (
            <div class="container">
                <br />
                <h1 class="text-center estilo-fuente">PROYECTO EMBEBIDOS</h1>
                <br />

                <h2 className="text-center">BIENVENIDO</h2>





                <h2 className="text-center">Datos relacionados en Firebase</h2>
                <br />
                {/* Distancia--------------------------------------- */}
                <div className="text-center">
                    <a href="" onclick="console.log('The link was clicked.'); return false" className="btn btn-primary btn-lg boton" size="70">
                        Distancia
                    </a>
                    <h2 className="text-center">
                        230
                    </h2>
                    <br />
                </div>
                {/* TEMPERATURA */}


                {/* Atemperatura----------------------------------------------- */}
                <div className="text-center">
                    <a href="" onclick="console.log('The link was clicked.'); return false" className="btn btn-primary btn-lg boton" size="70">
                        Temperatura
                    </a>
                    <h2 className="text-center">17.5</h2>
                    <br />

                </div>
                {/* Atemperatura----------------------------------------------- */}
                <div className="text-center">
                    <a href="" onclick="console.log('The link was clicked.'); return false" className="btn btn-primary btn-lg boton" size="70">
                        Humedad
                    </a>
                    <h2 className="text-center">63</h2>
                    <br />

                </div>
                <div className="text-center">
                    <a href="adduser" onclick="console.log('The link was clicked.'); return false" className="btn btn-primary btn-lg boton" size="70">
                        AGREGAR USUARIOS
                    </a>

                    <br /><br /><br />

                </div>

                <div className="text-center">
                    <a href="" onclick="console.log('The link was clicked.'); return false" className="btn btn-primary btn-lg boton" size="70">
                        ACTUALIZAR DATOS
                    </a>

                    <br /><br /><br />

                </div>
            </div >






        );
    }
}




export default principal;
