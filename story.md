| ![cinque hand study](images/cinque0037.jpg) | ![cinque hand study](images/cinque0038.jpg) | ![cinque hand study](images/cinque0025.jpg) |
|---------------------------------------------|---------------------------------------------|---------------------------------------------|
# The Story
I've used ortholinear and mechanical keyboards for years.
Upon discovering [Ergogen](https://ergogen.xyz/) 
and the [Flat Foot Fox](https://flatfootfox.com/) tutorials 
I felt compelled to measure the angles, motion, range, and tilt of my hands.
I used ink and paper to create heat maps from which I drew overlays in Ergogen.
From Ergogen output I built 3D-printed switch holders.
I iterated through seven versions to refine the shape of cinque.

I wanted a compact upgrade akin to my [Atreus](https://atreus.technomancy.us/) keyboard,
since I found it too limiting for a software development daily driver.
My goals were comfort, compact, and an integrated trackball.

My efforts moved to learning KiCad and figuring out how to trace a PCB 
(I would ultimately lay out the complete PCB three times).
I was convinced by a friend that I *must* include matrix RGB lighting.
Originally I planned a reversible board, but separate halves made the FPC trackball connector viable.
![single sided cinque made everything fit](images/cinque0045.jpg)

While wrapping up the PCB layout I began testing the trackball shape and bearing options
(and ended up merely verifying [wiwilwi's excellent post on KBD news](https://kbd.news/Trackball-bearing-comparison-1757.html)).
I wanted a trackball in the middle of the keyboard,
large (originally a 57.25mm billiard ball),
and to drive it via the extra pins a RP2040 ProMicro would provide.
![working trey trackball test](images/cinque0002.jpg)

The PCBs would include small breakout boards to mount the switches and lights 
and string it together with JST connectors to support experimenting with the fundamentals of the trackball.

Once I got the PCBs in hand and the first keyboard up and running the job switched to case design.
I purchased a Bambu Lab A1 to facilitate the iterations that refining each component required.

| ![cinque PCBs received](images/cinque0004.jpg)        | ![first cinque alive](images/cinque0008.jpg)                        |
|-------------------------------------------------------|---------------------------------------------------------------------|
| ![cinque flat case plus riser](images/cinque0040.jpg) | ![first wrist rest and billiard placeholder](images/cinque0019.jpg) |
| ![first integrated trackball](images/cinque0023.jpg)  | ![cinque 1.0 case with 44mm trackball housings](images/cinque0026.jpg)              |

Ultimately I ditched the billiard ball,
as it tracked poorly and pushed the keyboard halves apart.

| The trackball housing required a good deal of incremental refinement. There is a lot going on in a relatively small space. | <img src="images/cinque0027.jpg" alt="cinque wireless" width="70%"/> |
|----------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------|

I've also built the wireless/Nice!View "portable" board with a spacer. 
There's room for a large lipo battery beneath each half.

| ![cinque wireless](images/cinque0035.jpg) | ![cinque wireless](images/cinque0020.jpg) |
|-------------------------------------------|-------------------------------------------|

And here's where things stand in June 2025:

| ![cinque](images/cinque0033.jpg) | ![cinque](images/cinque0041.jpg) |
|----------------------------------|----------------------------------|
| ![cinque](images/cinque0043.jpg) | ![cinque](images/cinque0056.gif) |

My sole regret is the TRRS location, though I have been able to manage with some tight tolerances around the trackball.
A future revision may see a change in connector type to support relocation.
Need to give that a think.

Thanks for taking a look. 
Yes, I'm writing all this on the cinque.
Gateron KS-33 Banana switches are fantastic.
It is my daily driver for work and play.

I appreciate any comments, suggestions, or ideas.

