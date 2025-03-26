<h3>This repository involves Problem Set 2 Week 2 from the course CS50’s Introduction to Computer Science</h3>

Each folder contains different solutions to a set of given problems.

<h1>"scrabble.c" inside folder "scrabble": Scrabble</h1>

In the game of Scrabble, players create words to score points, and the number of points is the sum of the point values of each letter in the word.

A = 1,
B = 3,
C = 3,
D = 2,
E = 1,
F = 4,
G = 2,
H = 4,
I = 1,
J = 8,
K = 5,
L = 1,
M = 3,
N = 1,
O = 1,
P = 3,
Q = 10,
R = 1,
S = 1,
T = 1,
U = 1,
V = 4,
W = 4,
X = 8,
Y = 4,
Z = 10

For example, if we wanted to score the word “CODE”, we would note that the ‘C’ is worth 3 points, the ‘O’ is worth 1 point, the ‘D’ is worth 2 points, and the ‘E’ is worth 1 point. Summing these, we get that “CODE” is worth 7 points.

In a file called scrabble.c in a folder called scrabble, implement a program in C that determines the winner of a short Scrabble-like game. Your program should prompt for input twice: once for “Player 1” to input their word and once for “Player 2” to input their word. Then, depending on which player scores the most points, your program should either print “Player 1 wins!”, “Player 2 wins!”, or “Tie!” (in the event the two players score equal points).

Your program should behave per the examples below.

![image](https://github.com/user-attachments/assets/5b119f4a-f2b2-4ee5-855a-5e3a2c4466c5)

<h1>"readability" inside folder "readability": Scrabble</h1>

<h4><strong>Problem to Solve</strong></h4>

According to Scholastic, E.B. White’s Charlotte’s Web is between a second- and fourth-grade reading level, and Lois Lowry’s The Giver is between an eighth- and twelfth-grade reading level. What does it mean, though, for a book to be at a particular reading level?

Well, in many cases, a human expert might read a book and make a decision on the grade (i.e., year in school) for which they think the book is most appropriate. But an algorithm could likely figure that out too!

In a file called readability.c in a folder called readability, you’ll implement a program that calculates the approximate grade level needed to comprehend some text. Your program should print as output “Grade X” where “X” is the grade level computed, rounded to the nearest integer. If the grade level is 16 or higher (equivalent to or greater than a senior undergraduate reading level), your program should output “Grade 16+” instead of giving the exact index number. If the grade level is less than 1, your program should output “Before Grade 1”.

<h4><strong>Background</strong></h4>

So what sorts of traits are characteristic of higher reading levels? Well, longer words probably correlate with higher reading levels. Likewise, longer sentences probably correlate with higher reading levels, too.

A number of “readability tests” have been developed over the years that define formulas for computing the reading level of a text. One such readability test is the Coleman-Liau index. The Coleman-Liau index of a text is designed to output that (U.S.) grade level that is needed to understand some text. The formula is

index = 0.0588 * L - 0.296 * S - 15.8

where L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.

For the purpose of this problem, we’ll consider any sequence of characters separated by a space to be a word (so a hyphenated word like “sister-in-law” should be considered one word, not three). You may assume that a sentence:

<ul>
  <li>will contain at least one word;</li>
<li>will not start or end with a space; and</li>
<li>will not have multiple spaces in a row.</li>
</ul>

Under those assumptions, you might already be able to find a mathematical relationship between the number of words and the number of spaces.

You are, of course, welcome to attempt a more sophisticated solution that can tolerate multiple spaces between words! We’ve tuned check50 to accept either approach to spaces, so the choice is yours.

<h1>"substitution" inside folder "substitution": Substitution</h1>

In a substitution cipher, we “encrypt” (i.e., conceal in a reversible way) a message by replacing every letter with another letter. To do so, we use a key: in this case, a mapping of each of the letters of the alphabet to the letter it should correspond to when we encrypt it. To “decrypt” the message, the receiver of the message would need to know the key, so that they can reverse the process: translating the encrypt text (generally called ciphertext) back into the original message (generally called plaintext).

A key, for example, might be the string NQXPOMAFTRHLZGECYJIUWSKDVB. This 26-character key means that A (the first letter of the alphabet) should be converted into N (the first character of the key), B (the second letter of the alphabet) should be converted into Q (the second character of the key), and so forth.

A message like HELLO, then, would be encrypted as FOLLE, replacing each of the letters according to the mapping determined by the key.

In a file called substitution.c in a folder called substitution, create a program that enables you to encrypt messages using a substitution cipher. At the time the user executes the program, they should decide, by providing a command-line argument, on what the key should be in the secret message they’ll provide at runtime.

<h4><strong>Specifications</strong></h4>

Design and implement a program, substitution, that encrypts messages using a substitution cipher.

Implement your program in a file called substitution.c in a directory called substitution.
<ul>
<li>Your program must accept a single command-line argument, the key to use for the substitution. The key itself should be case-insensitive, so whether any character in the key is uppercase or lowercase should not affect the behavior of your program.</li>
<li>If your program is executed without any command-line arguments or with more than one command-line argument, your program should print an error message of your choice (with printf) and return from main a value of 1 (which tends to signify an error) immediately.</li>
<li>If the key is invalid (as by not containing 26 characters, containing any character that is not an alphabetic character, or not containing each letter exactly once), your program should print an error message of your choice (with printf) and return from main a value of 1 immediately.</li>
<li>Your program must output plaintext: (without a newline) and then prompt the user for a string of plaintext (using get_string).</li>
<li>Your program must output ciphertext: (without a newline) followed by the plaintext’s corresponding ciphertext, with each alphabetical character in the plaintext substituted for the corresponding character in the ciphertext; non-alphabetical characters should be outputted unchanged.</li>
<li>Your program must preserve case: capitalized letters must remain capitalized letters; lowercase letters must remain lowercase letters.</li>
<li>After outputting ciphertext, you should print a newline. Your program should then exit by returning 0 from main.</li>
</ul>
