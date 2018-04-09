---
layout: page
title: Project 4
category: top
permalink: hw4.html
menu: top
use_math: true
---

## Experiments on hearing

### Due Monday, March 26

#### Part 1: Frequency Discrimination

1. Using earphones, play two sine-wave tones of 200 Hz. Set the volume of each to 25% in your browser, then adjust the volume of the output until you can clearly hear the tones, but they are not uncomfortably loud.
Gradually increase the frequency of one of the tones. What do you hear?

2. One person should gradually increase the frequency of the upper tone until the other hears two distinct tones, rather than one wavery one. How far apart must the two tones be for you to clearly distinguish them?
How many semitones apart are these frequencies? (Remember, you can calculate the difference in semitones $s$ between two frequencies $f_1$ and $f_2$ as $s = 12 \log_2 (f_2/f_1) = 12 \frac{\log (f_2/f_1)}{\log (2)}$.)

3. (At home) Repeat the previous experiment at 500 Hz and 2000 Hz. (Since our hearing is more sensitive at 2 kHz, you will likely want to turn the volume on your computer down.)

4. Can you draw any conclusions about the "filter width" in human hearing, and how it varies with frequency, from your findings?

5. Play two tones of 400 and 405 Hz together using earphones. What do you hear? (This should not be unexpected.) Then, using the controls on the online tone generator, set one of them to "stereo left" and one of them to "stereo right". 
What has happened? Based on your observations here, what can you conclude about how "beats" are produced in human hearing?


#### Part 2: Nonlinearity of Speakers

1. (Do this for yourself at home -- I will demonstrate in class, but if everyone does this on their own, we'll have too much interference.) 
Using high-quality speakers if you have them, play two tones of 600 and 700 Hz. Set the volume in your web browser to around 35% for both.
Look at this on a spectrum analyzer. What do you see? (It should be what you expect. High-quality speakers give a linear response to all but the loudest sounds.)

2. Now, using low-quality speakers (such as those on a cellphone, tablet, or those built into a laptop), play first the 600 Hz tone at fairly high volume. Record the frequencies that you see on your spectrum analyzer. Then 
play the 700 Hz tone on your spectrum analyzer, and record the frequencies you see from it. Where do the extra frequencies come from?

3. Now, play the 600 and 700 Hz tones at the same time. Record the lowest five strong frequencies that you see, and explain where each one came from, using the principles of the "heterodyne mechanism". 

4. Now, play 400 Hz along with 805 Hz and listen for "beating". Do you hear any? Does this make sense, given the large separation in frequencies?

4. If your device has two speakers, like mine does, now play 600 Hz and 700 Hz together again, but set one of those tones to stereo left and one to stereo right. If you don't, borrow a friend's cellphone, and repeat the experiment using both of your cellphones together,
each playing one tone. What do you see now? Specifically, where did the 1300 Hz tone go?


#### Part 3: Nonlinearity of Ears

Now we want to test the nonlinear response of human hearing. Thus, we want to use only sound-producing devices that are themselves linear. This means good-quality speakers or earphones. (I don't have experience with the little earbuds
that come with iThings, but I imagine they are good enough.)

1. Using earphones, play two tones of 600 and 700 Hz at relatively low volume, both set to stereo center. (Set both of them to 35% volume in your web browser, and turn the volume on your device down.) What do you hear?

2. Now, turn the volume up on your device, earphones, or speakers gradually. **IMPORTANT: Do this gradually.** You want it to be loud enough to produce the kinds of effects we are looking for, but if you play a 
sudden pure sine wave at maximum amplitude through certain sorts of 
devices, you may damage your hearing. Listen specifically for a low-frequency tone that wasn't present before. Where does this tone come from?

3. Now, gradually decrease the frequency of the 600 Hz tone. What do you hear now? Specifically, what happens to the frequency of the low tone that you hear?

4. Now, play two tones (on headphones) of 300 Hz and 605 Hz. Adjust the frequency of the upper tone slightly, varying it from 595 Hz to 605 Hz in steps of 1 Hz. What do you hear now? 

5. Now, set the 300 Hz tone to stereo left, and the 605 Hz tone to stereo right. What happened?


#### Part 4: The Harmonic Sequence and Nonlinearity

Imagine that you have two objects which produce a range of frequencies when struck.

One of these is a violin string. Its fundamental is tuned to 400 Hz. It produces frequencies of 400 Hz, 800 Hz, 1200 Hz, 1600 Hz, 2000 Hz, etc., when played.

However, as you've learned, the nonlinear response of the human ear will produce *extra* frequencies that are not actually present in the signal. Which extra frequencies will the human ear perceive in this signal?

The other is some other shape of material. Its resonant frequences are a haphazard collection which are not a harmonic sequence. Suppose they are 300 Hz, 420 Hz, 880 Hz, 950 Hz, etc.

1. Calculate some of the extra frequencies that the human ear will produce in response to this signal. 
2. Will a listener hear "beating" in this sound, even though none of the frequencies are particularly close to one another?

#### Part 5 (Extra Credit): DTMF Tones

A touch-tone phone can encode up to sixteen different "buttons" as combinations of 
two frequencies. See <a href="https://en.wikipedia.org/wiki/Dual-tone_multi-frequency_signaling#Keypad">Wikipedia</a> for a chart of how this works. These tones are used for other types of signaling,
where short information needs to be encoded acoustically. (See the 1983 film *WarGames*, which is something of a late Cold War icon, for a hilarious representation of how this can be manipulated.)

Notice that *none* of these frequencies are multiples of one another, or are related by simple whole-number ratios. Additionally, no pair of tones has the same difference between them.

Given that DTMF tones are designed for signaling over noisy, crappy, distorted, nonlinear, awful communication channels in all kinds of conditions, why is this important?


