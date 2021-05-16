// vi:set nu ai ap aw smd showmatch tabstop=4 shiftwidth=4:

pipeline {
  agent any
  options {
    timestamps();
  }
  parameters {
    string (
	  description: 'Tag Override Value for suba',
	  name: 'tagovrsuba',
	  defaultValue: ''
	)
    string (
	  description: 'Tag Override Value for subb',
	  name: 'tagovrsubb',
	  defaultValue: ''
	)
    string (
	  description: 'Tag Override Value for subc',
	  name: 'tagovrsubc',
	  defaultValue: ''
	)
  }

  stages {
    stage('build in parallel') {
      parallel {
        stage('build suba') {
          steps {
            build job: 'suba',parameters: [[$class: 'StringParameterValue', name: 'subaovr', value: tagovrsuba]]
          }
        }
        stage('build subb') {
          steps {
            build job: 'subb',parameters: [[$class: 'StringParameterValue', name: 'subbovr', value: tagovrsubb]]
          }
        }
        stage('build subc') {
          steps {
            build job: 'subc',parameters: [[$class: 'StringParameterValue', name: 'subcovr', value: tagovrsubc]]
          }
        }
      }
    }
    stage('copy artifacts') {
      steps {
        script {
          step ([$class: 'CopyArtifact', 
              projectName: 'suba',
              filter: "sub*.deb",
              target: 'Collected']);
          step ([$class: 'CopyArtifact', 
              projectName: 'subb',
              filter: "sub*.deb",
              target: 'Collected']);
          step ([$class: 'CopyArtifact', 
              projectName: 'subc',
              filter: "sub*.deb",
              target: 'Collected']);
        }
      }
    }
  }
  post {
    always {
      
      archiveArtifacts artifacts: 'Collected/sub*.deb', onlyIfSuccessful: true
      step([$class: 'WsCleanup'])
    }
  }
}

