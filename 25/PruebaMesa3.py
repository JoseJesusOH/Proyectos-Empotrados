from MesaRectangular3 import MesaRectangular3
from MesaRedonda3 import MesaRedonda3


if __name__ == '__main__':
    mesas = []
    try:
        mesa1 =  MesaRectangular3('Cubierta Pino', 1.0, 1.0, 'Pata Pino')
    except Exception as e:
        print(f"No se pudo crear la mesa: {str(e)}")
    else:
        mesas.append(mesa1)
    
    try:
        mesa2 =  MesaRectangular3('Cubierta Pino', 1.0, 1.2, 'Pata Pino')
    except Exception as e:
        print(f"No se pudo crear la mesa: {str(e)}")
    else:
        mesas.append(mesa2)
        
    try:
        mesa3 = MesaRectangular3('Cubierta Pino', -1.0, 1.5, 'Pata Pino')
    except Exception as e:
        print(f"No se pudo crear la mesa: {str(e)}")
    else:
        mesas.append(mesa3)
        
    try:
        mesa4 = MesaRectangular3('Cubierta Cedro', 1.2, 1.5, 'Pata Cedro')
    except Exception as e:
        print(f"No se pudo crear la mesa: {str(e)}")
    else:
        mesas.append(mesa4)
        
    try:
        mesa5 =MesaRectangular3('Cubierta Cedro', 1.2, -1.5, 'Pata Cedro')
    except Exception as e:
        print(f"No se pudo crear la mesa: {str(e)}")
    else:
        mesas.append(mesa5)
                
    
    try:
        mesa6 = MesaRedonda3('Cubierta Pino', 0.50, 'Pino')
    except Exception as e:
        print(f"No se pudo crear la mesa: {str(e)}")
    else:
        mesas.append(mesa6)
    
    try:
        mesa7 = MesaRedonda3('Cubierta Pino', -0.6, 'Pino')
    except Exception as e:
        print(f"No se pudo crear la mesa: {str(e)}")
    else:
        mesas.append(mesa7)
        
    try:
        mesa8 = MesaRedonda3('Cubierta Pino', 0.6, 'Pino')
    except Exception as e:
        print(f"No se pudo crear la mesa: {str(e)}")
    else:
        mesas.append(mesa8)
        
    try:
        mesa9 = MesaRedonda3('Cubierta Cedro', 0.75, 'Cedro')
    except Exception as e:
        print(f"No se pudo crear la mesa: {str(e)}")
    else:
        mesas.append(mesa9)
        
    try:
        mesa10 = MesaRedonda3('Cubierta Cedro', -0.75, 'Cedro')
    except Exception as e:
        print(f"No se pudo crear la mesa: {str(e)}")
    else:
        mesas.append(mesa10)

    print(f"Número de mesas creadas: {len(mesas)}\n")


    for mesa in mesas:
        print(mesa)
        print(f"Área de la cubierta: {mesa.area()} m^2")
        print(f"Costo de la mesa: ${mesa.costo():.2f}\n")