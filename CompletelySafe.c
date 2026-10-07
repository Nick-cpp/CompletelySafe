#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <locale.h>

static int get_utf8_char_len(unsigned char c) {
    if ((c & 0x80) == 0) return 1;
    if ((c & 0xE0) == 0xC0) return 2;
    if ((c & 0xF0) == 0xE0) return 3;
    if ((c & 0xF8) == 0xF0) return 4;
    return 1;
}

static void wait_keypress(void) {
    struct termios oldt, newt;
    if (tcgetattr(STDIN_FILENO, &oldt) == 0) {
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    } else {
        getchar();
    }
}

static void p(const char *text, unsigned int delay_us) {
    if (text && *text) {
        const char *ptr = text;
        while (*ptr) {
            int len = get_utf8_char_len((unsigned char)*ptr);
            for (int i = 0; i < len && *ptr; i++) {
                putchar(*ptr++);
            }
            fflush(stdout);
            usleep(delay_us);
        }
        putchar('\n');
    }
    wait_keypress();
}

static void p_default(const char *text) {
    p(text, 20000);
}

static void clear_screen(void) {
    int res = system("clear");
    (void)res;
    printf("============================================================\n");
    fflush(stdout);
}

static int read_choice(void) {
    char buffer[32];
    printf("\n> ");
    fflush(stdout);
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        return atoi(buffer);
    }
    return 0;
}

int main(void) {
    setlocale(LC_ALL, "");

    /*Chapter 1*/
    clear_screen();
    p_default("It all started on that fateful day.");
    p_default("Windows 11 forced my PC into a reboot right in the middle of important work, without asking.");
    p_default("Along the way, yet another telemetry module and a built-in AI assistant got installed...");
    p_default("Something clicked in my head. I started digging through specialized tech forums.");
    p_default("I discovered Unix, Linux, GNU.");
    p_default("I instantly wanted to switch to a free operating system where I would be in control of my own computer.");
    p_default("My mind was spinning from the influx of ideas and the realization of all the possibilities.");
    p_default("That evening, I was looking for a GNU/Linux distribution that would suit me, while learning the basics of GNU/Linux systems.");
    p_default("I learned about init systems, specifically systemd.");
    p_default("This init system is used in almost every distribution—it seemed like a great product used by the majority!");
    p_default("I got curious; I enjoy studying the history of core system components.");
    p_default("An hour later, I decided to look into the history of systemd...");
    p_default("An init system developed by RedHat, which was genuinely convenient at its inception, leading most distributions to switch to systemd...");
    p_default("!!!");
    p_default("Over time, systemd started incorporating more and more components, and the codebase grew exponentially!");
    p_default("Why is PID 1 dragging along a network resolver, a session manager, and binary logs?!");
    p_default("Why does an init system need so many components!?");
    p_default("This isn't just bloated, monstrous software—it's a perfect Trojan horse!");
    p_default("I truly realized: corporations and American intelligence agencies have planted hidden backdoors in it. Under the guise of 'convenience', they created a monolithic tool for total system control!");
    p_default("Why are most distributions still condemning their users to using this!?");
    p_default("It's unacceptable, it's a betrayal!");
    p_default("Who audited the entire source code of systemd!?");
    p_default("Does anyone at all guarantee the reliability of this product!?");
    p_default("Moreover, the lead developer of systemd worked at Microsoft from 2022 to 2026!");
    p_default("He definitely cannot be trusted.");

    /*Chapter 2*/
    clear_screen();
    p_default("That night, I realized I had to choose a distribution wisely. I wanted to avoid systemd and other bloated components where developer-planted spy vulnerabilities could hide, waiting to hand data over to corporations and American intelligence agencies!");
    p_default("Browsing forum discussions, I stumbled upon something incredible: NoPersonalLife GNU/Linux.");
    p_default("It was a little-known distribution. Its author was clearly on my wavelength—zero clutter.");
    p_default("The author wrote their own init system in just 144 lines of code!? And their own package manager too.");
    p_default("It was the ideal choice!");
    p_default("This became the sole purpose of my life. I locked myself in my room. The system build began.");
    p_default("The phone rang. My home-room teacher's name flashed on the screen. She was scolding me for truancy and missing homework assignments.");
    p_default("School? What school!?");
    p_default("I didn't have time for them at all; I was trying to free myself from corporate domination.");
    p_default("Eight hours into compiling the system, my brain started slowing down. Every now and then, I drank overly strong tea, which tasted unpleasant at first.");
    p_default("But over time, I got used to it.");

    p_default("Days blurred into nights. Teacups covered the entire desk.");
    p_default("And then, after three days with almost no sleep...");
    p_default("A line flashed on the screen in a fraction of a second: 'NPL login: '");
    p_default("I felt incredibly pleasant vibrations pulsing inside my head, filling my whole mind.");

    /*Chapter 3*/
    clear_screen();
    p_default("Suddenly, the screen of the nearby smartphone glinted with another notification.");
    p_default("I realized a horrific truth: a mobile phone is a portable bugging device!");
    p_default("The cellular baseband processor has direct hardware-level access to the microphone and memory!");
    p_default("A cold chill ran through my body, a cold sweat broke out, wrapping me in a shiver...");

    p_default("For a moment, I felt hesitant, my hands shaking.");
    p_default("But I pulled the SIM card out of my phone and destroyed it.");
    p_default("WHAT HAVE I DONE!?..");
    p_default("I realized that my life wouldn't stop without a SIM card. I pushed forward.");
    p_default("Accounts across all messaging apps and social networks were ruthlessly deleted.");
    p_default("Next came the phone itself...");
    p_default("Trying not to think about anything, I removed the battery, wrapped the phone in aluminum foil, and stashed it on the top shelf of the closet.");
    p_default("Yet, for some reason, something was still troubling me...");

    /*Chapter 4*/
    clear_screen();
    p_default("I felt calmer.");
    p_default("I had been sitting in this room for nearly 80 hours, barely eating anything.");
    p_default("I thought I should probably get something to eat...");
    p_default("I stepped out of the room, feeling somewhat clumsy and anxious.");
    p_default("I walked to the fridge...");
    p_default("Strange... There was almost nothing left.");
    p_default("As much as I hated the thought of it, I had to go to the store.");
    p_default("I got dressed, feeling safe and hidden inside a large black hoodie.");
    p_default("Hopefully, it would make it easier to survive this trip.");
    p_default("I walked out into the stairwell, locked the apartment, and headed down the stairs.");
    p_default("I felt like I hadn't locked the apartment...");
    p_default("Anxiety hit me again.");
    p_default("I turned back and checked the door.");
    p_default("It was locked.");
    p_default("Relieved, I left the building.");
    p_default("It was still dark outside.");
    p_default("Barely anyone was around, nobody was looking at me.");
    p_default("Usually, it's very hard for me to handle people's gazes.");
    p_default("When people look at me, I feel like they suspect something.");
    p_default("And I start feeling extremely self-conscious.");
    p_default("I start worrying that I'm putting my feet down weirdly while walking.");
    p_default("Or something along those lines.");
    p_default("And that people are staring because they notice it.");
    p_default("So I start controlling my every movement to avoid drawing attention.");
    p_default("Every step, every movement of my hands.");
    p_default("It's exhausting, because when I move my arm, for instance, I have to consciously stop the motion at the right moment.");
    p_default("And maintain a natural speed on top of that.");
    p_default("Controlling my legs is even harder...");
    p_default("In those moments, my legs usually tremble and give way.");
    p_default("But right now it was around 4 AM, there was almost no one on the street, and nobody was looking at me.");
    p_default("I felt a sense of relief.");
    p_default("Though it was a bit chilly outside—a very unpleasant sensation.");
    p_default("I made it to the nearest 24/7 supermarket.");
    p_default("I grabbed a box of pasta and a can of stewed meat.");
    p_default("Thank goodness self-checkout registers exist nowadays.");
    p_default("Arriving back home, I took off my hoodie.");
    p_default("About 15 minutes to cook navy-style pasta.");
    p_default("During those 15 minutes, I drifted off into thought again.");
    p_default("In moments like these, I forget who I am and what I was doing.");
    p_default("I just think about anything at all, and sometimes it really pulls me in.");
    p_default("Like pondering how people once came up with a particular invention.");
    p_default("Pondering fictional characters.");
    p_default("Or simply trying to calculate something like: how many times heavier than a fly is my plate.");
    p_default("I drift into these thoughts especially often after stress or when I lack the energy to take action.");
    p_default("This time, for some reason, I started thinking about my PC.");
    p_default("Cold sweat broke out again, and I felt a wave of cold.");
    p_default("I ate quickly and ran back to my room.");

    /*Chapter 5*/
    clear_screen();
    p_default("I realized that my Intel CPU contained Intel Management Engine, with full access to my PC bypassing the OS.");
    p_default("And the NVidia graphics card running on proprietary drivers.");
    p_default("Sure, open-source drivers could be used, but they require closed kernel blobs to function.");
    p_default("My PC was literally crawling with hardware implants from American intelligence services!");

    p_default("With trembling hands, I sold my PC for cash.");
    p_default("Because banks store information about my transactions too.");

    p_default("I bought an old Thinkpad X200.");
    p_default("Even though it was a very old laptop, its power would be enough for me.");
    p_default("Besides, it's one of the few laptops where you can flash open-source GNU boot and get rid of Intel ME.");
    p_default("A day later, everything was ready: I bought a programmer, a SOIC clip, and the laptop was lying on my desk.");
    p_default("I spent a few minutes taking it apart.");

    p_default("I attached the clip to the BIOS chip, and shortly after, the laptop was freed from the proprietary BIOS.");
    p_default("I took a pre-prepared flash drive with the Parabola GNU/Linux-libre livecd.");
    p_default("I started the installation.");
    p_default("A routine task—how many times had I done this before?");
    p_default("I knew half of these steps by heart.");
    p_default("Partitioning the drive: 1 megabyte for GRUB, 4 gigabytes for swap, and the rest for root.");
    p_default("I mounted the root partition and activated swap.");
    p_default("I installed the necessary packages following instructions I had hand-written on paper beforehand.");
    p_default("Overall, the distribution was actually quite nice; installation took literally 10 minutes.");

    /*Chapter 6*/
    clear_screen();
    p_default("I am sitting in complete darkness.");
    p_default("Here it is, freedom: free GNU boot, a free OS, no phone that can eavesdrop on me at any moment.");
    p_default("And then a final, icy terror struck me...");
    p_default("The ISP! It knows my IP addresses, domain names, and the exact TIME of my connections!");
    p_default("Neither VPN nor Tor can hide the fact that the ISP knows when I go online!");

    /*Ending*/
    clear_screen();
    p_default("I save all package sources, documentation, and articles onto external hard drives.");
    p_default("The ethernet cable is unplugged and cut with scissors.");
    p_default("Now I don't go online. At all. Ever.");
    p_default("I am completely safe.");

    wait_keypress();
    return 0;
}
