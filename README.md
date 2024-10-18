# 2024-group-17

[![pipeline status](https://git.chalmers.se/courses/dit638/students/2024-group-17/badges/main/pipeline.svg)](https://git.chalmers.se/courses/dit638/students/2024-group-17/-/pipelines) [![test coverage](https://git.chalmers.se/courses/dit638/students/2024-group-17/badges/main/coverage.svg)](https://git.chalmers.se/courses/dit638/students/2024-group-17/-/jobs) [![latest release](https://git.chalmers.se/courses/dit638/students/2024-group-17/-/badges/release.svg)](https://git.chalmers.se/courses/dit638/students/2024-group-17/-/releases)



## Getting started

To make it easy for you to get started with GitLab, here's a list of recommended next steps.

Already a pro? Just edit this README.md and make it your own. Want to make it easy? [Use the template at the bottom](#editing-this-readme)!

## Add your files

- [ ] [Create](https://docs.gitlab.com/ee/user/project/repository/web_editor.html#create-a-file) or [upload](https://docs.gitlab.com/ee/user/project/repository/web_editor.html#upload-a-file) files
- [ ] [Add files using the command line](https://docs.gitlab.com/ee/gitlab-basics/add-file.html#add-a-file-using-the-command-line) or push an existing Git repository with the following command:

```
cd existing_repo
git remote add origin https://git.chalmers.se/courses/dit638/students/2024-group-17.git
git branch -M main
git push -uf origin main
```

## Integrate with your tools

- [ ] [Set up project integrations](https://git.chalmers.se/courses/dit638/students/2024-group-17/-/settings/integrations)

## Collaborate with your team

- [ ] [Invite team members and collaborators](https://docs.gitlab.com/ee/user/project/members/)
- [ ] [Create a new merge request](https://docs.gitlab.com/ee/user/project/merge_requests/creating_merge_requests.html)
- [ ] [Automatically close issues from merge requests](https://docs.gitlab.com/ee/user/project/issues/managing_issues.html#closing-issues-automatically)
- [ ] [Enable merge request approvals](https://docs.gitlab.com/ee/user/project/merge_requests/approvals/)
- [ ] [Set auto-merge](https://docs.gitlab.com/ee/user/project/merge_requests/merge_when_pipeline_succeeds.html)

## Test and Deploy

Use the built-in continuous integration in GitLab.

- [ ] [Get started with GitLab CI/CD](https://docs.gitlab.com/ee/ci/quick_start/index.html)
- [ ] [Analyze your code for known vulnerabilities with Static Application Security Testing (SAST)](https://docs.gitlab.com/ee/user/application_security/sast/)
- [ ] [Deploy to Kubernetes, Amazon EC2, or Amazon ECS using Auto Deploy](https://docs.gitlab.com/ee/topics/autodevops/requirements.html)
- [ ] [Use pull-based deployments for improved Kubernetes management](https://docs.gitlab.com/ee/user/clusters/agent/)
- [ ] [Set up protected environments](https://docs.gitlab.com/ee/ci/environments/protected_environments.html)

***

# Our workflow 



 Introduction
This document provides step-by-step instructions on how to set up and build [Project Name]. This process is designed to be executed in a terminal, suitable for environments where a GUI is not available, such as embedded systems or remote servers accessed via SSH. 


 Prerequisites


Before you begin, ensure that the following tools are installed on your system:


- `git` - For cloning the repository.


- Compiler/toolchain (e.g., `gcc` for C/C++ projects)




Install these tools using your system's package manager. For example, on Ubuntu or Debian-based systems, you can use:

''
sudo apt-get update
sudo apt-get install git make gcc
''
Adjust the command to include the appropriate tools for your project.


 Cloning the Repository:
Step 1: Open a terminal 
Step 2:  Navigate to the desired  directory where you want to clone the repository.:
		cd /path/to/your/directory
Step 3: Clone the repository to the path using the SSH::
Gitclone git@git.chalmers.se:courses/dit638/students/2024-group-17.git

Step4:‘Change into the project directory:
cd projectname

Step 5: Check out to an clean folder:
git checkout main
git pull origin main
Step 6: Building the project: 
Once you have cloned the repository, you can build the project by following these steps:

1. To build the project, run the build command specific to the  project's build system.
2. Use different branches for each developer where they 
git add,
 git commit -m ”message”, 
and git push 
their code

 As a conclusion, following these instructions should allow you to clone and build the Project  successfully in a terminal environment. This workflow is designed for ease of automation and compatibility with text-based interfaces, such as those found in embedded systems or when accessing remote systems via SSH.


How is our team working to:


Adding New Features:
When a new feature is agreed upon by the team, we initiate the development process by creating an issue in GitLab for that feature. This ensures that every new feature is tracked and managed efficiently. Each issue is then assigned to a team member responsible for implementing the feature. This approach keeps our workflow organized and ensures accountability. 

Fixing Unexpected Behavior in Existing Features:
Unexpected behaviors or bugs in existing features are typically identified through merge conflicts or when branches are found to be behind the main branch by several commits. To address these issues:


- Merge Conflicts: We resolve conflicts by reviewing the differences and making decisions based on the context of the changes. This might involve direct edits in the GitLab interface or resolving conflicts locally on a developer's machine before pushing the resolved version to the repository.
  
- Outdated Branches: For branches that are lagging, we update them by merging or rebasing them with the main branch. This ensures that all branches are up-to-date and reduces the likelihood of integration issues.


These fixes benefit from our feature branch workflow and code review processes, ensuring that any change is reviewed and tested before being integrated into the main codebase.


What shall be the structure and content of our commit messages 
Our commit messages play a crucial role in understanding the history and purpose of changes. We use a structured format for our commit messages:
(Git commit -m “ Detailed-message”) structure:


“If applied, this commit show your subject line here”
For example:
If applied, this commit will refactor subsystem X for readability



## Name
Group17.

## Description
Let people know what your project can do specifically. Provide context and add a link to any reference visitors might be unfamiliar with. A list of Features or a Background subsection can also be added here. If there are alternatives to your project, this is a good place to list differentiating factors.



## Visuals
Depending on what you are making, it can be a good idea to include screenshots or even a video (you'll frequently see GIFs rather than actual videos). Tools like ttygif can help, but check out Asciinema for a more sophisticated method.

## Installation
Cloning the Repository

Step 1: Open a terminal 
Step 2:  Navigate to the desired  directory where you want to clone the repository.:
		cd /path/to/your/directory
Step 3: Clone the repository to the path using the SSH::
Gitclone git@git.chalmers.se:courses/dit638/students/2024-group-17.git

Step4:‘Change into the project directory:
cd projectname

Step 5: Check out to an clean folder:
git checkout main
git pull origin main
Step 6: Building the project: 
Once you have cloned the repository, you can build the project by following these steps:


## Support
please open an issue in the repository. We're here to help and support.

## Roadmap
If you have ideas for releases in the future, it is a good idea to list them in the README.

## Contributing

 We Welcome Contributions

We're open to, and grateful for, any contributions made by the community. By participating in this project, you agree to abide by our code of conduct and contribute to an inclusive environment for everyone.

## Getting Started

Before you make your first contribution, please follow these steps:

1. **Familiarize Yourself with the Project**: Understand its objectives, architecture, and existing functionalities.
2. **Setup Your Development Environment**: Depending on the project, you may need to:
   - Install specific software or tools (like Docker, specific IDEs, or compilers).
   - Set environment variables critical for the project's configuration.
   - Run an initial setup script that prepares your local environment. 

## Making Changes

1. **Fork and Clone the Repository**: Make sure you have a GitLab account. Fork the repository, then clone your fork and create a new branch for your changes.



3. **Making Contributions**: Whether you're adding new features, fixing bugs, or improving documentation, your contributions are welcome.

## Code Quality and Testing


- **Write Tests**: If you're adding new features, writing tests for your code is crucial. Ensure your tests cover the new functionality and don't break existing tests.

## Submitting Your Contributions

Once you're ready to submit your changes:

1. **Push Your Changes**: Push your changes to your fork and submit a pull request to the original repository.

2. **Describe Your Changes**: In your pull request, provide a clear description of the changes and any additional instructions for testing or setup that reviewers might need.

## Review Process

Our team will review your submission as soon as possible. We may request changes or provide feedback. Engaging with feedback and working towards improving your contribution is highly valued.

## Questions or Suggestions?

If you have questions or suggestions, please open an issue in the repository. We're here to help and appreciate any feedback to improve the project.

ds.

## Authors and acknowledgment
[Ahmed Algabri,Amanda Turquis,David Hong,David Rocha]

## License
# MIT License

Copyright (c) 2024 [Ahmed Algabri,Amanda Turquis,David Hong,David Rocha]  

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

## Project status
If you have run out of energy or time for your project, put a note at the top of the README saying that development has slowed down or stopped completely. Someone may choose to fork your project or volunteer to step in as a maintainer or owner, allowing your project to keep going. You can also make an explicit request for maintainers.
