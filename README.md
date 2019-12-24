# Cinema booking system
This repository contains classes for a cinema booking system.
User can select movie,room, time, seats and place order. 
The system includes following object: movie,room, track(in which room when which movie is showing), seat, user, order(a user
books which track and which seats) 
Additionally, this system can be extended to be used for cinema administrator to plan movie(when to plan which movie in which
room) in order to get the most audience and income.


# Download source
Feel free to clone repository
  git clone https://github.com/Mathieu-93/cinema-booking-system.git

# Brief remaind
1. Install git aplication ->https://git-scm.com/download/ 
2. Use GIT BASH
3. Local command:
  - git add (whatever file you wnt to add) / -git add . (ALL)
  - git commit -m "Please leave me a message"
   Global:
  - git push <- you push file to repository 
  - git pull <- updated your previous rep
4. Cheack your modification-> git status
  - if file is UNTRACKED it's mean that it is not ready to be committed you should add first
5. Branching:
  - git branch <-cheack
  - git branch feature1 <-new branch
  - git cheakout feature1 <-switch branch
  - git merge master <-pull reuest
  
  example How to make some commits and merge it back into master: 
  
  git checkout master
  git branch new-branch 
  git checkout new-branch
 ...Develop some code...
  git add -A
  git commit -m "some commit message"
  git checkout master <-Note that git merge merges the specified branch into the currently active branch
  git merge new-branch
  
6.When you solve the conflict you must repeat all precedure git all/commit/push but in commit there will be a message window to leave press:
  - (ESC) :wq
 
