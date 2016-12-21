package jlppc.regimys.core;

import jlppc.regimys.launch.Start;

/**
 * Enum�ration d�crivant le status actuel du jeu.
 * @author Jlppc
 *
 */
public enum GameState {
	/**
	 * Quand le jeu est a l'arret
	 */
	ARRET,
	/**
	 * Quand le jeu est en marche
	 */
	MARCHE,
	/**
	 * Quand le jeu est en pause (Ferm�, dans le menu ect
	 */
	PAUSE,
	/**
	 * Quand un dialogue est en cours
	 */
	DIALOGUE;
	
	public static Thread stateThread;
	public static GameState state = MARCHE;
	
	static{
		stateThread = new Thread(new Runnable(){

			@Override
			public void run() {
				while(true){
					if(state != MARCHE){
						try {
							Start.gameThread.wait();
						} catch (InterruptedException e) {
							e.printStackTrace();
							System.exit(1);
						}
					}else{
						Start.gameThread.notify();
					}
				}
				
			}
			
		});
	}
}
