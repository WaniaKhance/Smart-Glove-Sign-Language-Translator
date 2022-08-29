# Smart Glove - Sign LanguageTranslator


* Introduction
  ------------

Communication is a fundamental aspect of human life, speech-impaired people depend on the other means of communication like sign language (a non verbal form of intercourse). To bridge this communication gap, it is important to have an advance sign-language detection and gesture recognition system for people in the community when they try to engage in interaction with normal public that do not understand sign-language. In this project, we have developed 'Smart Glove' - a sign language translator. It consists of both hardware and software modules for translation purpose. We perform real-time translation of hand gesture into speech and text.

We have collected a dataset by ourselves and provided in the documents. 

  ------------

For Hardware:

We have used

1. Cotton glove
2. Arduino microprocessor: receives analog data from different sensors and provess it for further analysis. 
3. Flex sensors: determine the bending of each finger of one hand and sends data to microprocessor
4. Wifi module: connects arduino to the computer/laptop device for wireless communication between glove and the device. 
5. Gyroscope: determines the angular position of the hand in space and sends three plane x, y and z-axis values to microprocessor. 
6. Electrical wires: for connection of different sensors, wifi module and microprocessor. 

For Software:

1. Arduino IDE
2. Anaconda - Spyder IDE


 * Requirements
  ------------
The provided code works in all python versions above 3.7.0.

 * Installation
  ------------

There are few libraries that need to be installed which are given in the code file. 
