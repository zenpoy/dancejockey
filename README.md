dancejockey
===========
A sonification of movement and visualization of sound

## Design
### Jockey
This is the player. The Jockey generates events such as *bpm changed*, etc.
the Jockey is listening to the raw events such as handMove, mouseMoved,etc.
The jockey process these events and sends a meaningful event. 

### Instrument
An instrument is an object that listens to the Jockeys' events and produce audio / visual signals and generates other events.

## Brainstorming
- multiple players, each controlling independently over sound
- together their movement creates a visual image (audio-visual feedback)
- For each chosen instrument the user have different type of movement-sound integration but that doesn't mean that other movements (which don't have an effect on the specific instrument) goes to waste - they still goes into account when generating the video/image and by that effect the other player.
- in other words I would say that you choose a complementary audiovisual instrument
- e.g. One player is controlling the strings (pads), so his tiny-sharp movement have no effect on the string only flow-like slow movements changes the color and he tone of the string, but still if the tiny-sharp movements are represented on the shared visual and effects the drum player!